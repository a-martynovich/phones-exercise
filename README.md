# Omilia test task

When interacting with an automated dialogue system, the caller is often required to provide his phone number. Phone numbers may be uttered in many ways with different digit groupings (e.g. 2106930664 may be uttered as "210 69 30 6 6 4" or "210 69 664" etc). Furthermore, speech input may cause ambiguities. For example, if the caller says "twentyfive" this could be transcribed as "25" or "20 5".

## Running the code

`./phones <merge|validate|ambiguities> "number"`

Make sure to enclose the number in quotes!

* `merge` - simply merges input numbers into one;
* `validate` - tells if it's a valid Greek phone number;
* `ambiguities` - generates all variants of a number and tells if they are valid.

## Building the code
```
mkdir build
cd build
cmake ..
make
```

## Running tests
Tests are written with GTest and GMock and are built together with the program. Running tests is as simple as `./phones-test`.
