#include <iostream>

char* encode(const char* str, unsigned int length, Symbol** symbols, unsigned int &lengthOutput){
    for(int i = 0; i < 255; i++){
        symbols[i]::count = 0;
    }
    for(int i = 0; i < length; i++){
        for(int j = 0; j < 255; j++){
            if(symbols[j]::symbol == str[i]){
                symbols[i]::count++;
            }
        }
    }
    lengthOutput = codingTree.count();
    char* result = new char[lengthOutput];
    CodingTree* codingTree = createCode(symbols, result);
    return result;
}
void decode(const char* encoded, unsigned int length, Symbol** symbols, char* str){
    unsigned int read = 0;
    CodingTree* codingTree = createEncoding(symbols);
    while(read <= length)
        str = str + codingTree.decode(encoded[read], read);
}
int main(){
    unsigned int compressedLength = 0;
    Symbol* symbols[255];
    for(int i = 0; i < 255; i++){
        symbols[i]::symbol = i;
    }
    char t[] = "All the world's a stage, and all the men and women merely players.";
    char* code = encode(t,67,symbols, compressedLength);
    char* res = new char[66];
    decode(code, compressedLength, symbols, res);
    delete[] res;
    char c;
    std::cin >> c;
    return 0;
}
