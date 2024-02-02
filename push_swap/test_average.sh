#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Usage: $0 <iterations> <numbers to test>"
    exit 1
fi

iterations=$1
num_numbers=$2
total_instructions=0

# lock_file=$(mktemp)

run_push_swap() {
    ARG=$(gshuf -i 0-5000 -n $num_numbers)
    IS_OK=$(./push_swap $ARG | ./checker $ARG)
    instructions=$(./push_swap $ARG | wc -l)
    total_instructions=$((total_instructions + instructions))
    echo "Iterations $i: Instructions - $instructions"
}

# export -f run_push_swap

for ((i = 1; i <= iterations; i++)); do
    run_push_swap
done

# seq $iterations | xargs -I {} -P 2 bash -c 'i={} run_push_swap'
# rm "$lock_file"

average=$((total_instructions / iterations))
echo
echo
echo "Average Instructions: $average"
echo

#wait
