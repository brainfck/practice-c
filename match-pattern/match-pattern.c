int starmatch(const char* str, const char* pat);
int match(const char* str, const char* pat){
    switch(*pat){
        case 0:
            return *str == 0;
        case '?':
            if(!*str)
                return 0;
            return match(str+1, pat+1);
        case '*':
            return starmatch(str, pat+1);
        default:
            if(*str != *pat)
                return 0;
            return match(str+1, pat+1);
    }
}

int starmatch(const char* str, const char* pat){
    int i;
    for(i=0; ; i++){
        int res = match(str+i, pat);
        if(res)
            return 1;
        if(!str[i])
            return 0;
    }
}
