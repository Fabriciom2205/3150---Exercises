#include <vector>

bool non_neg_prefix_sum(int lst[], int size) {
    int current_sum = 0;
    for (int i = 0; i < size; i++) {
        current_sum += lst[i];
        if (current_sum < 0) {
            return false; 
        }
    }
    return true;
}

bool non_pos_prefix_sum(int lst[], int size) {
    int current_sum = 0;
    for (int i = 0; i < size; i++) {
        current_sum += lst[i];
        if (current_sum > 0) {
            return false;
        }
    }
    return true;
}