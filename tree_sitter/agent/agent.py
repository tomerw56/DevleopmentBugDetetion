import requests
from qdrant_client import QdrantClient

QDRANT_URL = "http://localhost:6333"
COLLECTION = "cpp_code_chunks"
LLM_MODEL = "qwen2.5-coder:7b"
EMBED_MODEL = "nomic-embed-text"

client = QdrantClient(url=QDRANT_URL)


def embed(text: str):
    resp = requests.post(
        "http://localhost:11434/api/embeddings",
        json={
            "model": EMBED_MODEL,
            "prompt": text
        }
    )
    resp.raise_for_status()
    return resp.json()["embedding"]


def chat(prompt: str):
    resp = requests.post(
        "http://localhost:11434/api/generate",
        json={
            "model": LLM_MODEL,
            "prompt": prompt,
            "stream": False
        }
    )
    resp.raise_for_status()
    return resp.json()["response"]


def retrieve(query, limit=4):
    vec = embed(query)
    hits = client.query_points(
        collection_name=COLLECTION,
        query=vec,
        limit=limit
    )
    return hits


def build_prompt(query, hits):
    context = []
    for h in hits.points:
        context.append(h.payload["contextualizedText"])

    joined = "\n\n---\n\n".join(context)

    return f"""
You are a C++ code assistant.

User question:
{query}

Relevant code:
{joined}

Instructions:
- Answer using ONLY the provided code.
- If fixing a bug, show a minimal diff or replacement function.
- Be precise.

Answer:
"""


def main():
    print("Local C++ AST Agent (type 'exit' to quit)\n")

    #what is the problem with the devide method
    while True:
        q = input(">> ")
        if q.strip().lower() in ("exit", "quit"):
            break

        hits = retrieve(q)
        prompt = build_prompt(q, hits)

        answer = chat(prompt)
        print("\n--- AGENT ---")
        print(answer)
        print("--------------\n")


if __name__ == "__main__":
    main()
