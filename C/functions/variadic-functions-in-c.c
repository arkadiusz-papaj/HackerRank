int sum (int count,...) {
    va_list arg_list;
    int sum = 0;
    va_start(arg_list, count);
    
    for (size_t i = 0; i < count; i++){
        sum += va_arg(arg_list, int);
    }
    
    va_end(arg_list);
    return sum;
}

int min(int count,...) {
    va_list arg_list;
    va_start(arg_list, count);
    int min = (1<<31) - 1;

    for (size_t i = 0; i < count; i++){
        int arg = va_arg(arg_list, int);
        min = (arg < min) ? arg : min;
    }
    
    va_end(arg_list);
    return min;
}

int max(int count,...) {
    va_list arg_list;
    va_start(arg_list, count);
    int max = (1<<31) * (-1);

    for (size_t i = 0; i < count; i++){
        int arg = va_arg(arg_list, int);
        max = (arg > max) ? arg : max;
    }
    
    va_end(arg_list);
    return max;
}