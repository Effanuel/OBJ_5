# OBJ_5
1. Išveda kiek kiekvienas žodis pasikartoja kartų tekste ir kuriose eilutėse *(indeksai nuo 1)*;
2. Suranda visus URL adresus naudojant regex ir išveda į konsolę
---
## Prerequisites
1. GNU C++ Compiler

## Installation
1. [Atsisiūskite naujausią versiją.]()
2. Extract failus.
3. Per command-line:
```
cd OBJ_5
make run
```
4. Executable yra **./3_uzduotis/bin/project.exe**
```
cd bin
./project
```
---
## Regular Expression code:
```Regex
((http|https):\/{2})?(?=\4)(www\.)?(\w+\.(com|org|lt)){1}
```

## Sample text:
Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitaehttps://www<nolink>. dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione <b>www<nolink>.vu.lt</b>voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia **http<nolink>://www<nolink>.vu.com** dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis **https<nolink>://vu.lt**ostrum exercitationem ullam **corporis.lt** suscipit laboriosam, nisi ut **aliquid.org** ex ea commodi consequatur? Quis autem vel eum iure reprehenderit quiwww.volter .com in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?
  
---

