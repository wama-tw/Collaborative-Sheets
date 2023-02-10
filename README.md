## 編譯

可以使用 makefile.sh 來編譯（用 g++）

```sh
./makefile.sh
```

自己編譯的話，可以參考 makefile.sh 裡的指令，把所有 cpp 檔一起編譯即可。

```sh
g++ Main.cpp Views/*.cpp Models/*.cpp Database.cpp Controllers/*.cpp -o FinalProject.out
```

## 使用

和[助教給的 Example](https://trusted-minnow-271.notion.site/Final-Project-044948ed08f1422baeab8a01295e41a6) 一模一樣，可以參考 example.txt（裡面放的是助教給的 Example）。

## Features

1. Able to create users
2. Let users can create their new sheet
3. Let users can print out their sheet
4. Let users can change the content of their sheet
5. Let sheet has two access rights, read-only or editable, for every user.
6. Let users can share their sheet with other users
7. Let sheets can deal with rational arithmetic `+` , `-` , `*` , `/` .
   Possible input: rational number like `123.456` , `123` and operators like `+` , `-` , `*` , `/` .

- Furthermore, please make the requirements 5. & 6. can be easily switched on/off.
  > For instance, to switch off the requirement 5. , you can remove some code, not inherit some class, or not generate some object, etc.
