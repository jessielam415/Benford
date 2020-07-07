#include <stdio.h>
//#include <math.h>
#include "benford_helpers.h"

int power(int x, int n) { 
  int result; 
  if (n == 0) { 
    result = 1; } 
  else { 
    result = x; 

    for (int i = 0; i < n - 1; i++) { 
      result = result * x; 
    } 
  } 
  return result;
 }


int count_digits(int num) {
    // TODO: Implement.
    if (num == 0) {
        return 1;
    }
    int counter = 0;
    double i = num; 
    while(i >= BASE) {
        i = i/BASE;
        counter++;
    } 
    if (i > 0) {
        return (int) counter + 1;
    } else {
        return (int) counter;
    }
}

int get_ith_from_right(int num, int i) {
    // TODO: Implement.
    int get_ith_from_left(int num, int i);
    int count = count_digits(num);
    return get_ith_from_left(num, count - 1 - i);
}

int get_ith_from_left(int num, int i) {
    int count_digits(int num);
    int count = count_digits(num);
    int arr[count];
    int remainder = num;
    for (int b = 0; b < count; b++) {
        int base_to_power = (int) power(BASE, count - 1 - b);
        if (remainder >= base_to_power){
            int power_of = remainder/base_to_power;
            arr[b] = power_of;
            remainder = remainder % base_to_power;
        } else {
            arr[b] = 0;
        }
    } return arr[i];
}

void add_to_tally(int num, int i, int *tally) {
    int get_ith_from_left(int num, int i);
    int digit_to_add = get_ith_from_left(num, i);
    tally[digit_to_add] = tally[digit_to_add] + 1;
}
