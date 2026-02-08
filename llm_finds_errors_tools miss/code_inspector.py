import subprocess
from pathlib import Path
import sys

RULES = Path("rules.txt").read_text()
CODE  = Path(sys.argv[1]).read_text()

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

response=result.stdout
print(response)
with open(sys.argv[1].replace(".cpp","_llm_response.txt"), "w") as f:
  f.write(response)