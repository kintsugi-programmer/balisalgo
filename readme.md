# balisalgo ;)
Ek Tuhi Nirankar

/patterns/patterns.md# Patterns
/patterns/patterns.md#/patterns/patterns.md# Table of Contents
- [Patterns](/patterns/patterns.md#patterns)
  - [Table of Contents](/patterns/patterns.md#table-of-contents)
  - [Tips](/patterns/patterns.md#tips)
  - [Pattern - 1: Rectangular Star Pattern](/patterns/patterns.md#pattern---1-rectangular-star-pattern)
  - [Pattern - 2: Right-Angled Triangle Pattern](/patterns/patterns.md#pattern---2-right-angled-triangle-pattern)
  - [Pattern - 3: Right-Angled Number Pyramid](/patterns/patterns.md#pattern---3-right-angled-number-pyramid)
  - [Pattern - 4: Right-Angled Number Pyramid - II](/patterns/patterns.md#pattern---4-right-angled-number-pyramid---ii)
  - [Pattern - 5: Inverted Right Pyramid](/patterns/patterns.md#pattern---5-inverted-right-pyramid)
  - [\* Pattern - 6: Inverted Numbered Right Pyramid](/patterns/patterns.md#-pattern---6-inverted-numbered-right-pyramid)
  - [\* Pattern - 7: Star Pyramid TO BE REView](/patterns/patterns.md#-pattern---7-star-pyramid-to-be-review)
  - [Pattern - 8: Inverted Star Pyramid](/patterns/patterns.md#pattern---8-inverted-star-pyramid)
  - [Pattern - 9: Diamond Star Pattern](/patterns/patterns.md#pattern---9-diamond-star-pattern)
  - [\* Pattern - 10: Half Diamond Star Pattern](/patterns/patterns.md#-pattern---10-half-diamond-star-pattern)
  - [\* Pattern - 11: Binary Number Triangle Pattern](/patterns/patterns.md#-pattern---11-binary-number-triangle-pattern)
  - [Pattern - 12: Number Crown Pattern](/patterns/patterns.md#pattern---12-number-crown-pattern)
  - [Pattern - 13: Increasing Number Triangle Pattern](/patterns/patterns.md#pattern---13-increasing-number-triangle-pattern)
  - [\* Pattern - 14: Increasing Letter Triangle Pattern](/patterns/patterns.md#-pattern---14-increasing-letter-triangle-pattern)
  - [Pattern - 15: Reverse Letter Triangle Pattern](/patterns/patterns.md#pattern---15-reverse-letter-triangle-pattern)
  - [Pattern - 16: Alpha-Ramp Pattern](/patterns/patterns.md#pattern---16-alpha-ramp-pattern)
  - [\* Pattern - 17: Alpha-Hill Pattern](/patterns/patterns.md#-pattern---17-alpha-hill-pattern)
  - [Pattern - 18: Alpha-Triangle Pattern](/patterns/patterns.md#pattern---18-alpha-triangle-pattern)
  - [Pattern - 19: Symmetric-Void Pattern](/patterns/patterns.md#pattern---19-symmetric-void-pattern)
  - [Pattern - 20: Symmetric-Butterfly Pattern](/patterns/patterns.md#pattern---20-symmetric-butterfly-pattern)
  - [\* Pattern - 21: Hollow Rectangle Pattern](/patterns/patterns.md#-pattern---21-hollow-rectangle-pattern)
  - [\* Pattern - 22: The Number Pattern](/patterns/patterns.md#-pattern---22-the-number-pattern)
    - [Context](/patterns/patterns.md#context)
    - [Detailed Explanation](/patterns/patterns.md#detailed-explanation)
      - [Variables](/patterns/patterns.md#variables)
      - [Computation](/patterns/patterns.md#computation)
      - [Subtracting from `n`](/patterns/patterns.md#subtracting-from-n)
    - [Example Walkthrough](/patterns/patterns.md#example-walkthrough)
      - [At position `(0, 0)`:](/patterns/patterns.md#at-position-0-0)
      - [At position `(1, 1)`:](/patterns/patterns.md#at-position-1-1)
      - [At position `(4, 4)` (center):](/patterns/patterns.md#at-position-4-4-center)


## Tips
- Don't Dive Deep
- Think and try brute force and when done and found new at solution ,take notes
- retry without video
- Do contests as much as possible even you know to solve 1 problem
- and no need to do 450 ques,just 300 are fine.also it has depth dsa which almost al l companies lack

## Code Setup
![alt text](image.png)
- create input.txt
- create output.txt
- create code.cpp
- .vscode/tasks.json
  ```
    {
      "version": "2.0.0",
      "tasks": [
          {
              "label": "compile",
              "type": "shell",
              "command": "g++",
              "args": [
                  "-std=c++17",
                  "-o",
                  "${fileBasenameNoExtension}",
                  "${file}"
              ],
              "group": {
                  "kind": "build",
                  "isDefault": false
              }
          },
          {
              "label": "compile and run",
              "type": "shell",
              "command": "bash",
              "args": [
                  "-c",
                  "g++ -std=c++17 -o ${fileBasenameNoExtension} ${file} && ./${fileBasenameNoExtension} < input.txt > output.txt"
              ],
              "group": {
                  "kind": "build",
                  "isDefault": true
              }
          }
      ]
  }

  ```
  - Ctrl + Shift + B
