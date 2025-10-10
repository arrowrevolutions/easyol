Easyol(tm) — Minimal Header-Only C++ Array Toolkit (v0.0.4)

One file. Zero drama.
Lightweight, readable, and contest-friendly C++ utilities for arrays and simple 2D data (via arr<arr<T>>). Made to save time in contests and classrooms — copy-paste the header, include, and go.


---

TL;DR

Single header: easyol.hpp.

arr<T> — thin, smart wrapper over std::vector<T> with Python-like ergonomics (append, negative indices, pop, etc.).

Fast: size() is O(1) (internal len), small binary footprint, zero external deps.

arr<arr<T>> works as a matrix — no separate mat required.

Configurable by macros for tiny builds.



---

Quickstart

Copy easyol.hpp into your project and include it:

#include "easyol.hpp"
using namespace std;

int main() {
  arr<int> a = {1,5,2,6,3};
  a.sort(true);     // reverse sort
  cout << a;        // prints a single-line array
}

Compile normally:

g++  main.cpp -O3 -o main


---

Key Features & API (short)

Constructors: arr<T>(), arr<T>({1,2,3}).

void readarray(unsigned long rows = 1) — read 1 (or more) lines from stdin (skips empty lines).

bool load_file(const std::string& name) — load one line from a text file into the array.

bool save_as(const std::string& name) — save array to a text file.

void append(T), void del(long index = -1), std::optional<T> pop(long index = -1) — Python-like convenience.

unsigned long size() const noexcept — O(1) (uses internal len).

void sort(bool reversed = false), void reverse().

T& operator[](long index) — supports negative indexes (a[-1] last element).

friend std::ostream& operator<<(std::ostream&, const arr<T>&) — stream output.

Optional math operators (+, *, /, +=, etc.) controlled by macros.



---

Example: contest-style I/O

#define NO_IO
#include "easyol.hpp"
using namespace std;

int main() {
  int n; cin >> n; cin.ignore();
  arr<int> a;
  a.readarray();     // read a single line of numbers
  a.sort(true);      // reverse
  cout << a;         // nice output
}

Matrix example with arr<arr<int>>:

arr<arr<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
m.save_as("out.txt");        // writes lines
// To read a matrix from stdin:
// for rows: call readarray(rows) on an arr<arr<int>> (it reads rows lines)


---

Macro configuration (place before #include "easyol.hpp")

#define NO_IO — disable extra tuple input helper.

#define NO_ARR_MATH_OPERATOR — disable array math operators (+, -, *, /).

#define NO_ARR_EQ_MATH_OPERATOR — disable +=, /= etc.
Use macros to slim the header for contest builds.



---

Design notes (short & honest)

Not a full std::vector replacement. arr is a pragmatic, contest-minded layer on top of std::vector. data is public so advanced users can still reach into the raw vector.

len is private: it’s an internal performance counter — use calibrate() if you mess with data directly.

Focus: reduce boilerplate and friction, not to invent new abstractions. Keep it explicit and predictable.



---

Changelog (v0.0.4)

arr stabilized with core operations: append, del, pop, reverse, index, sort.

readarray(rows) handles multiple lines robustly (skips empty lines).

load_file / save_as — simple text file I/O for quick verification and testing.

Better arr<arr<T>> support (practical matrix usage without separate class).



---

Roadmap (short)

v0.0.5: small niceties (optional map/filter, minor I/O helpers).

v0.1.0: stable release with examples & basic CI.
If the community wants more (matrix ops, safe-mode checks), they’ll grow into separate modules — no bloat.



---

License

MIT — use it, fork it, build on it. If you publish or ship it publicly, a short credit to A.R. is appreciated.


---

Where to share / how to help

If you like Easyol:

Star the repo, open issues for bugs or feature ideas.

Share simple examples (Codeforces templates, classroom exercises).

Want help writing a short demo post or README polish? I can generate ready-to-publish text.



---

Final word

Easyol isn’t magic. It’s a tool that cuts the boring stuff out of contest code and classroom demos: faster setup, less boilerplate, clearer logic. If you want readable C++ that gets the job done — drop easyol.hpp into your project and start solving.

WE.ARE.NEW.ERA — A.R. (easyol v0.0.4)



easyol™ is a trademark of A.R. Unauthorized use of the name is prohibited

Just include (or cut and paste,lol)  and work

python-like ergonomic, c++ native speed
