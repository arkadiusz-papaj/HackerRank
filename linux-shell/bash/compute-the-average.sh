read no_of_numbers
sum=0

for ((i=0; i<$no_of_numbers; i++)); do
    read number
    sum=$(($sum+$number))
done

printf "%.3f" $(echo "$sum/$no_of_numbers" | bc -l)