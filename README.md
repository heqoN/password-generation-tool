# Password Generator and Encryption Program

This project is a simple C-based tool for **password generation**, **password encryption (XOR)**, and **password decryption**.

The program includes the following features:

* Random password generation
* Customizable password contents (numbers, letters, special characters)
* Option to write generated passwords to a file
* XOR-based encryption
* Decryption of hex-encoded XOR output

---

## 📌 Features

### **1. Password Generator**

The user is prompted for:

* Number of passwords to generate
* Password length
* Include numbers? (Yes/No)
* Include characters? (Yes/No)
* Include special characters? (Yes/No)
* Write passwords to file? (Yes/No)

Generated passwords are printed to the screen and optionally saved to `passwords.txt`.

---

### **2. Password Encryptor (XOR)**

The user enters:

* Password
* Key

The program applies XOR encryption and prints the result in **hexadecimal format**.

It also prints the **password length**, which is required for decryption.

---

### **3. Password Decryptor (XOR)**

To decrypt, the user provides:

* Original password length
* Encrypted password in hex format
* Key

The XOR operation is reversed and the original password is displayed.

---

## 🛠 Compilation

To compile the program:

```bash
gcc program.c -o program
```

Run it with:

```bash
./program
```

On Windows:

```bash
gcc program.c -o program.exe
program.exe
```

---

## 📄 Generated Files

| File              | Description                                                     |
| ----------------- | --------------------------------------------------------------- |
| **passwords.txt** | Contains generated passwords if the user chooses to write them. |

---

## 📌 Key Techniques Used

* Random character selection using `rand()`
* Simple XOR-based encryption
* Hexadecimal encoding and decoding for encrypted data
