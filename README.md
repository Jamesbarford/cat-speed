# Speed cat
_how fast is a cat? 😸_

## What do these cats do 🐈?
Read files sequentially printing to standard out.

## Usage
- source ./cat_speed.sh
- `init_cats` will compile all code.

Use like so for performance testing:

- `time ./output/cat_alt [file ...]`
- `time ./output/cat_kr [file ...]`
- `time ./output/cat_++ [file ...]`

e.g:
```bash
$ time ./output/cat_alt file_1 file_2 ...
```

## Observations
1. `cat_alt`
2. `cat` -> original, whatever is rolled with Mac Big sur
3. `cat++`
4. `cat_kr`