# Supermarket Billing System in C++

## Description

This is a simple console-based **Supermarket Billing System** built using C++.
It allows two types of users:

- **Administrator** (to manage products)
- **Buyer** (to purchase products and generate receipt)

The system uses **file handling** to store and retrieve product details.

---

## Features

### Administrator

- **Add Product** — Add new products with code, name, price, and discount.
- **Edit Product** — Modify existing product details.
- **Delete Product** — Remove products from the database.
- **View Product List** — View all available products.

> **Login Required**\
> Default Credentials:\
> **Email:** `jude24@gmail.com`\
> **Password:** `Jude123`

---

### Buyer

- **View Products** — See the list of available products.
- **Purchase Products** — Select multiple products, specify quantity.
- **Get Receipt** — View bill with price, quantity, discount, and total.

---

## File Structure

| File           | Description                           |
| -------------- | ------------------------------------- |
| `database.txt` | Stores product details (auto created) |
| `main.cpp`     | Source code of the project            |

---

## How to Run

1. Copy the code into a file named `main.cpp`.
2. Compile using a C++ compiler:\
   `g++ main.cpp -o supermarket`
3. Run the executable:\
   `./supermarket` (Linux/Mac)\
   `supermarket.exe` (Windows)

---

## Sample Credentials

| User Type | Email                                        | Password |
| --------- | -------------------------------------------- | -------- |
| Admin     | [jude24@gmail.com]                           | Jude123  |

---

## Notes

- Product details are saved in `database.txt` in the same directory.
- Uses basic **file I/O** and simple **object-oriented programming** concepts.
- Works in Turbo C++ or any modern C++ compiler.

---

