import json
import requests
from qdrant_client import QdrantClient
from qdrant_client.models import VectorParams, Distance, PointStruct

QDRANT_URL = "http://localhost:6333"
COLLECTION = "cpp_code_chunks"
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


def main():
    with open("../chunker/out/chunks.json", "r", encoding="utf-8") as f:
        chunks = json.load(f)

    # Create collection (idempotent-ish for demo)
    dim = len(embed("test"))
    client.recreate_collection(
        collection_name=COLLECTION,
        vectors_config=VectorParams(size=dim, distance=Distance.COSINE)
    )

    points = []
    for idx, chunk in enumerate(chunks):
        vec = embed(chunk["contextualizedText"])

        payload = {
            "file": chunk["file"],
            "scope": chunk["scope"],
            "defines": chunk["defines"],
            "code": chunk["code"],
            "contextualizedText": chunk["contextualizedText"]
        }

        points.append(
            PointStruct(
                id=idx,
                vector=vec,
                payload=payload
            )
        )

    client.upsert(collection_name=COLLECTION, points=points)
    print(f"[+] Ingested {len(points)} chunks into Qdrant")


if __name__ == "__main__":
    main()
