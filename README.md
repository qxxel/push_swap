# push_swap
![42 Project](https://img.shields.io/badge/42-Project-blue)
![Language](https://img.shields.io/badge/C-0E7FC0?logo=c)

---

## 📌 Summary
- [About](#about)
- [Features](#features)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Directories structure](#directories-structure)
- [Author](#author)

---

<a id="about"></a>
## 📖 About

**push_swap** is a project of 42 school.
It's a program that's sort a list of numbers, given as argument, with two stacks in the program. It will return all instructions to sort the input. 

---

<a id="features"></a>
## ✨ Features

✅ Take and parse a list of number in argument  
✅ Handle two stacks and instruction to move the numbers  
✅ Optimize the program to be fast in time and instructions  
✅ Error management  
✅ Create a checker for this project

---

<a id="installation"></a>
## ⚙️ Installation

**1. Clone the repository**

```bash
git clone git@github.com:qxxel/push_swap.git
```

**2. Access the directory**

```bash
cd push_swap
```

---

<a id="utilisation"></a>
## 🕹️ Utilisation

**1. Compile the project**

```bash
make
```

**2. Launch it with a list of numbers**

```bash
./push_swap [list of numbers]
```

You can generate random numbers with `shuf`:
```bash
$(shuf -i 0-999 -n 10)
```
* `-i 0-999` → number range (0 to 999 here)
* `-n 10` → how many numbers you want to generate (10 here)
* `$( ... )` → insert directly the `shuf` result as an argument

---

<a id="directories-structure"></a>
## 📂 Directories structure

```plaintext
📂 push_swap
 ┣ 📂 includes   → headers files (.h)
 ┣ 📂 libft      → my own C library (you can see on my profile)
 ┣ 📂 srcs       → sources files (.c)
 ┣ Makefile
 ┗ README.md
```

<a id="author"></a>
## 👤 Author

* Axel – [GitHub](https://gitub.com/qxxel)
* 42 student - login: *agerbaud*
