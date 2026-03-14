# GameDev Utils (C++)

I built this to fill gaps I kept hitting while making 2D games in C++. No frameworks, no bloat—just the bits I reused across projects. All classes are header-only, self-contained, and SDL-independent *except* where noted.

## What’s in here

### `Timer`
- Starts, stops, pauses, resumes (with `Reset()`, `Pause()`, `Unpause()`, etc.)
- `GetTicks()` returns milliseconds since start (uses SDL_GetTicks)
- No drift—Delta time is just `tickDelta / 1000.0f`

### `Vector2D`
- Basic ops: `+`, `-`, `*`, `/` (scalar), `==`, `!=`
- `Normalize()`, `Magnitude()`, `Distance(other)`
- `Dot()`, `Cross()` (2D cross returns scalar z-component)
- `Rotate(angleDeg)` modifies in place
- Static helpers: `Zero()`, `UnitX()`, `UnitY()`, `FromPolar(r, thetaDeg)`
- No dynamic allocation. All inlined.

### `Animation`
- Frame sequences stored as `std::vector<int>` under the hood
- Methods: `Next()`, `Prev()`, `Rewind()`, `SetFrame(index)`, `SetCurrentAnimation(name)`
- `GetCurrentFrame()`, `GetCurrentIndex()`, `GetLength()`, `GetName()`
- Add animations with `AddAnimation(name, frames)` (frames = `std::vector<int>`)
- `Test()` function included—run it to validate behavior (simple self-check)

### `Base64`
- `Encode(std::string)` → `std::string`
- `Decode(std::string)` → `std::string` (throws on invalid input)
- Pure C++ (no external deps), uses only STL. Handles padding.

## Usage

1. Grab the headers (`Timer.h`, `Vector2D.h`, `Animation.h`, `Base64.h`)
2. Drop them into your project tree
3. `#include "..."` where needed  
   *(For `Timer`, link `-lSDL2`)*

Example minimal `main.cpp`:

```cpp
#include "Vector2D.h"
#include "Timer.h"
#include <iostream>

int main() {
    Vector2D v{1.0f, 0.0f};
    v.Rotate(90.0f); // v is now (0, 1)
    
    Timer t;
    t.Start();
    // ... do work ...
    std::cout << "Elapsed: " << t.GetTicks() << "ms\n";
}
```

## Requirements

- C++17 compatible compiler (GCC 9+, Clang 9+, MSVC 2019+)
- SDL2 only for `Timer` (CMake optional; just link `-lSDL2`)
- No external dependencies beyond STL and SDL2

## Why this exists

I tired of copy-pasting half-broken vector math or debugging timing quirks from different tutorials. This is what I actually ship—tested in 3 small commercial-ish projects. If it breaks, I fix it. PRs welcome, but keep it simple.

—MIT license. See [LICENSE](LICENSE).