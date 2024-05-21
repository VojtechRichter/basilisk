# Basilisk

## Desired usage

input
```
Build the index:

basilisk -b document1.txt document2.html document3.pdf -o index.bsk


Build & Traverse the index

basilisk -i document1.txt document2.html document3.pdf -f "search phrase"
```

output
```
Search done [160ms]

result: {
    "searched phrases": ["search", "phrase"],

    "search": [
        document1: {
            line: ...,
            col: ...,
            count: 56
        },
        document25: {
            count: 5,
            ...
        }
    ],

    "phrase": [
        document3829: {
            ...
        }
    ]
}
```

## TODO

### Multiple document format support
    - [-] raw ascii
    - [-] txt
    - [-] html
    - [-] pdf
    - [-] xml

### Compressed archive peeking
    - [-] zip
    - [-] tar
    - [-] rar
    - [-] gzip
    - [-] bzip

### Output

    - [-] figure out the output format
    - [-] perhaps even support multiple output formats?

### Index file format
    - [ ] Compression?
### Document format priority
### Stemming
### Language recognition