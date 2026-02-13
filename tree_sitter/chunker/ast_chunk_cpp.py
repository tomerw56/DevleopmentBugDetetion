import os
import json
from tree_sitter import Language,Parser
import tree_sitter_cpp

CPP_LANGUAGE = Language(tree_sitter_cpp.language())
parser = Parser(CPP_LANGUAGE)

SRC_ROOT = "../cpp_code/src"

def read_file(path):
    with open(path, "r", encoding="utf-8") as f:
        return f.read()

def node_text(source, node):
    return source[node.start_byte:node.end_byte]

def extract_chunks(tree, source_code, file_path):
    root = tree.root_node
    chunks = []

    def walk(node):
        # Function definitions
        if node.type == "function_definition":
            code = node_text(source_code, node)
            sig = extract_signature(node, source_code)

            chunk = build_chunk(
                file_path=file_path,
                scope="global",
                defines=sig,
                code=code
            )
            chunks.append(chunk)

        # Class definitions
        if node.type == "class_specifier":
            class_name = extract_class_name(node, source_code)
            code = node_text(source_code, node)

            chunk = build_chunk(
                file_path=file_path,
                scope=class_name,
                defines=f"class {class_name}",
                code=code
            )
            chunks.append(chunk)

        for child in node.children:
            walk(child)

    walk(root)
    return chunks


def extract_signature(node, source):
    # crude but effective for demo
    for child in node.children:
        if child.type == "function_declarator":
            return node_text(source, child)
    return "unknown_function"


def extract_class_name(node, source):
    for child in node.children:
        if child.type == "type_identifier":
            return node_text(source, child)
    return "UnknownClass"


def build_chunk(file_path, scope, defines, code):
    contextualized = f"""# File: {file_path}
# Scope: {scope}
# Defines: {defines}

{code}
"""

    return {
        "file": file_path,
        "scope": scope,
        "defines": defines,
        "code": code,
        "contextualizedText": contextualized
    }


def main():
    all_chunks = []

    for file in os.listdir(SRC_ROOT):
        if not file.endswith(".cpp") and not file.endswith(".h"):
            continue

        full_path = os.path.join(SRC_ROOT, file)
        source = read_file(full_path)

        tree = parser.parse(bytes(source, "utf8"))
        chunks = extract_chunks(tree, source, full_path)
        all_chunks.extend(chunks)

    os.makedirs("out", exist_ok=True)
    with open("out/chunks.json", "w", encoding="utf-8") as f:
        json.dump(all_chunks, f, indent=2)

    print(f"[+] Extracted {len(all_chunks)} AST chunks")


if __name__ == "__main__":
    main()
