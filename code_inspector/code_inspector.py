import subprocess
from pathlib import Path

RULES = Path("rules.txt").read_text()
CODE  = Path("demo.cpp").read_text()

prompt = f"""
{RULES}

Review the following code:

```cpp
{CODE}
"""
result = subprocess.run(
["ollama", "run", "qwen2.5-coder:7b"],
input=prompt,
text=True,
capture_output=True
)

print(result.stdout)