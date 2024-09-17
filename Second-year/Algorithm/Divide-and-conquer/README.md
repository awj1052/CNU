# QuickSelect Performance Comparison of Different Methods in Python

1. built-in sorting method
2. random pivot
3. random good pivot
4. median of medians by size

# Results by Attempt on Raspberry Pi 4

## Attemp 1
```
quickselect_sort        1.128739357 sec
quickselect_random      0.360892773 sec function calls: 15
quickselect_random_good 1.741346598 sec function calls: 18      pivot average: 1.89
quickselect_mom5        2.280280113 sec function calls: 2535
quickselect_mom11       1.388347149 sec function calls: 318
quickselect_mom15       1.256570578 sec function calls: 189
quickselect_mom101      1.057196379 sec function calls: 15
quickselect_mom251      1.085785389 sec function calls: 9
quickselect_mom501      1.081508875 sec function calls: 5
```

## Attempt 2
```
quickselect_sort        1.089385748 sec
quickselect_random      0.496380806 sec function calls: 17
quickselect_random_good 1.259021282 sec function calls: 18      pivot average: 2.11
quickselect_mom5        2.430281401 sec function calls: 2481
quickselect_mom11       1.367170334 sec function calls: 325
quickselect_mom15       1.221357107 sec function calls: 188
quickselect_mom101      1.069355011 sec function calls: 15
quickselect_mom251      1.082772255 sec function calls: 9
quickselect_mom501      1.088281870 sec function calls: 5
```

## Attempt 3
```
quickselect_sort        1.100199461 sec
quickselect_random      0.580735445 sec function calls: 14
quickselect_random_good 1.437638998 sec function calls: 18      pivot average: 2.22
quickselect_mom5        2.251821280 sec function calls: 2357
quickselect_mom11       1.352459908 sec function calls: 333
quickselect_mom15       1.217826128 sec function calls: 189
quickselect_mom101      1.056288958 sec function calls: 15
quickselect_mom251      1.089426994 sec function calls: 9
quickselect_mom501      1.093806982 sec function calls: 5
```

## Attempt 4 (10^8 on AMD Ryzen 5 7600 6-Core Processor)
```
quickselect_sort        35.497492552 sec
quickselect_random      40.087744474 sec        function calls: 24
quickselect_random_good 91.662081242 sec        function calls: 26      pivot average: 1.69
quickselect_mom5        82.306732655 sec        function calls: 46787
quickselect_mom11       53.524627209 sec        function calls: 3199
quickselect_mom15       48.622855425 sec        function calls: 1608
quickselect_mom101      43.710798025 sec        function calls: 85
quickselect_mom1001     45.616707325 sec        function calls: 15
```
