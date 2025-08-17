# 🛒 Supermarket Billing System in C++

[![C++](https://img.shields.io/badge/Language-C++-blue.svg)](https://isocpp.org/)  
[![Beginner Project](https://img.shields.io/badge/Project-Type%3A%20Beginner-lightgrey)]()  
[![License: Free to Use](https://img.shields.io/badge/License-Free-brightgreen.svg)]()  

---

## 📝 Overview  

This project is a simple **Supermarket Billing System** developed using **C++**.  
It simulates a small shop environment with options for **Administrator** and **Buyer**.  
Designed for beginners to understand **Object-Oriented Programming (OOP)** concepts like Classes, Objects, File Handling, and Menu-Driven Applications.  

---

## 🎯 Features  

- 🛠️ **Administrator Panel**  
  - Add Products  
  - Edit Product Details  
  - Delete Product  
  - View Product List  

- 🛒 **Buyer Panel**  
  - View Product List  
  - Place Orders  
  - Generate Receipt with Total Amount and Discount  

- 📝 **Product Data Stored in a File (`database.txt`)**  

- 🗑️ Prevent Duplicate Product Codes  

- 🔁 Menu-driven Loop for Continuous Operations  

---

## 📜 Menu Options  

### 🛠️ Administrator Menu:  
[1] Add Product  
[2] Modify Product  
[3] Delete Product  
[4] Back to Main Menu  

### 🛒 Buyer Menu:  
[1] Buy Product  
[2] Go Back  

### 🏠 Main Menu:  
[1] Administrator (Login Required)  
[2] Buyer  
[3] Exit  

---

## 🗃️ Sample Admin Login Credentials  

Email: jude24@ gmail.com <br>
Password: Jude123


---

## 💻 How to Run  

1. Copy the code into a `.cpp` file.  
2. Compile using any C++ compiler.  
3. Ensure the executable can read/write `database.txt`.  
4. Use Admin Panel to add products before accessing Buyer Panel.  
5. Buy products and check the generated receipt.  

---

## 🧩 Code Concepts Used  

- ✅ Object-Oriented Programming (OOP)  
- ✅ File Handling with `fstream`  
- ✅ Menu-Driven Programming  
- ✅ Authentication & Validation  
- ✅ Data Validation with Duplicate Checks  

---

## 📷 Sample Console Output  


```text
____________________________________________
                                            
          Super Market Main Menu            
____________________________________________

|        1) Administrator                   |
|        2) Buyer                           |
|        3) Exit                            |

Please select your choice: 1


Please Login
Enter the Email : jude24@gmail.com
Password : Jude123


        Administrator Menu

|     1) Add the product       |
|     2) Modify the product    |
|     3) Delete the product    |
|     4) Back to the main menu |

Please Enter your choice: 1

Add New Product
 Product code of the product: 101
 Name of the product: Soap
 Price of the product: 30
 Discount on product: 5

Record inserted!
```

```text
BUYER

1) Buy Product
2) Go Back

Enter your choice: 1

_____________________________________________________
Product No     Name            Price
_____________________________________________________
101            Soap            30

Please place the order
Enter the Product code: 101
Enter the product quantity: 2
Do you want to buy another product? if yes then press y else n: n

______________________RECEIPT__________________
Product No   Name       Quantity   Price   Amount   Discounted Price
101          Soap       2          30      60       57

Total Amount: 57
```


---

## 📖 License  

[![License: Free to Use](https://img.shields.io/badge/License-Free-brightgreen.svg)]()  

This project is open for educational and personal use.  
You are free to modify and experiment with it.  

---


