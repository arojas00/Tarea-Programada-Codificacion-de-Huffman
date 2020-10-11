#include <iostream>
#include <cstring>
char* encode(const char* str, unsigned int length, Symbol** symbols, unsigned int &lengthOutput){
    symbols count = 0;
    for(int i = 0; i < length; i++){
        if(symbols symbol == str[i]){
            symbols count++;
        }
    }
    CodingTree* codingTree = createEncoding(symbols);
    lengthOutput = codingTree.count();
    char* result = new char[lengthOutput];
    // aqui va el punto 6e
    return result;
}
void decode(const char* encoded, unsigned int length, Symbol** symbols, char* str){
    unsigned int read = 0;
    CodingTree* codingTree = createEncoding(symbols);
    while(read <= length)
        str = str + codingTree.decode(encoded[read], read);
}
int main(){
    Symbols symbols[255];
    for(int i = 0; i < 255; i++){
        symbols[i] symbol = i;
    }
    char t[] = "All the world's a stage, and all the men and women merely players.";
    char* code = encode(t,67,symbols, compressedLength);
    char* res = new char[66];
    decode(code; outputLength, symbols, res);
    delete[] res;
    char c;
    std::cin >> c;
    return 0;
}
