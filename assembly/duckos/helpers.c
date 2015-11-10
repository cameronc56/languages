void itoa(int input, char *output) {
    char const digit[] = "0123456789";
    if(input < 0) {
        *output++ = '-';
        input *= -1;
    }
    int shifter = input;
    do { //Move to where representation ends
        ++output;
        shifter = shifter/10;
    } while(shifter);
    *output = '\0';
    do { //Move back, inserting digits as you go
        *--output = digit[input%10];
        input = input/10;
    } while(input);
}
