#!/bin/sh

for FILE in test_*.c; do
    [ -e "$FILE" ] || continue  # skip if no matches

    clang-format -i "$FILE"

    OUTPUT="${FILE%.c}.o"

    echo "[COMPILE] $FILE -> $OUTPUT"
    if gcc "$FILE" -o "$OUTPUT" -Wall -Wextra -Werror -pedantic; then
        ./"$OUTPUT"
        echo
    else
        echo "[ERROR] $FILE"
        echo
    fi
done
