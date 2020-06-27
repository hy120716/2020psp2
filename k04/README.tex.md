# 課題4 レポート

bb35319031 橋口裕太

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
l.6:ID,性別、身長の構造体sampleを宣言。，

l.25~50:性別、身長の入ったファイルからデータを読み込み、構造体の中のgender,heightsに格納。

l.53~72:IDの入ったファイルからデータを読み込み、構造体の中のIDに格納。

l.80~97:欲しいIDを聞き、それが構造体sampleにあればそのIDと性別、身長を出力。

l.100:なければ"No data"と出力。

## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```
```
PS C:\Users\bb35319031\プログラミング\2020psp2\k04> gcc k04.c -o k04.exe
PS C:\Users\bb35319031\プログラミング\2020psp2\k04> ./k04.exe
input the filename of sample heights ?:../sample/heights.csv
the filename of sample heights: ../sample/heights.csv
input the filename of sample ID ?:../sample/IDs.csv
the filename of sample ID: ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
heights : 152.40
```
```
input the filename of sample heights ?:../sample/heights.csv
the filename of sample heights: ../sample/heights.csv
input the filename of sample ID ?:../sample/IDs.csv
the filename of sample ID: ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```


## 修正履歴

