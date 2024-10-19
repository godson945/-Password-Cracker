# Password Cracker

## Overview
This project implements a simple password cracker using a dictionary attack. It attempts to find a plaintext password by hashing a list of common passwords and comparing the hashes.

## Features
- Cracks hashed passwords using a predefined list of common passwords.
- Uses the `crypt` library to hash passwords.

## How to Use
1. Clone the repository or download the files.
2. Modify the `hashed_password` variable in `password_cracker.c` with the hash you want to crack.
3. Ensure you have a file named `passwords.txt` in the same directory, containing a list of potential passwords.
4. Compile the code:
   ```bash
   gcc -o password_cracker password_cracker.c -lcrypt
