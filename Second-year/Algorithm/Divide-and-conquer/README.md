# QuickSelect Performance Comparison of Different Methods in Python

1. built-in sorting method
2. random pivot
3. random good pivot
4. median of medians by size

# Results by Attempt on Raspberry Pi 4

## Attemp 1
```
quickselect_sort        1.139248133 sec
quickselect_random      0.702947855 sec function calls: 19
quickselect_random_good 2.091781378 sec function calls: 21      pivot average: 2.00
quickselect_mom5        2.525417328 sec function calls: 2481
quickselect_mom11       1.395113707 sec function calls: 321
quickselect_mom15       1.260304213 sec function calls: 184
quickselect_mom101      1.061853170 sec function calls: 15
```

## Attempt 2
```
quickselect_sort        1.098165751 sec
quickselect_random      0.387420177 sec function calls: 13
quickselect_random_good 1.678702116 sec function calls: 16      pivot average: 1.62
quickselect_mom5        2.280402184 sec function calls: 2545
quickselect_mom11       1.376885176 sec function calls: 317
quickselect_mom15       1.236789465 sec function calls: 188
quickselect_mom101      1.056569338 sec function calls: 15
```

## Attempt 3
```
quickselect_sort        1.127684355 sec
quickselect_random      0.743086338 sec function calls: 20
quickselect_random_good 1.823818922 sec function calls: 20      pivot average: 2.15
quickselect_mom5        2.257797241 sec function calls: 2569
quickselect_mom11       1.372911453 sec function calls: 320
quickselect_mom15       1.236001253 sec function calls: 188
quickselect_mom101      1.056239128 sec function calls: 15
```