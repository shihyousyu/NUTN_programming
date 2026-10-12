#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class ZipCode{
    private:
        string barcode;
        static string encodeGroup(int digit){
            static const string codes[10] = {
                "11000", "00011", "00101", "00110", "01001",
                "01010", "01100", "10001", "10010", "10100"
            };
            return codes[digit];
        }
        static int decodeGroup(const string& group){
            for(int digit = 0; digit < 10; ++digit)
                if(group == encodeGroup(digit)) return digit;
            throw invalid_argument("Invalid POSTNET digit.");
        }
        int decodeBarcode() const{
            int zipCode = 0;
            for(size_t i = 1; i < 26; i += 5)
                zipCode = zipCode * 10 + decodeGroup(barcode.substr(i, 5));
            return zipCode;
        }
        static string encodeBarcode(int zipCode){
            if(zipCode < 0 || zipCode > 99999) throw invalid_argument("ZIP code must be in 0..99999.");
            string result;
            for(int i = 0; i < 5; ++i){
                result = encodeGroup(zipCode % 10) + result;
                zipCode /= 10;
            }
            return "1" + result + "1";
        }
    public:
        ZipCode(int zipCode) : barcode(encodeBarcode(zipCode)){}
        ZipCode(const string& value) : barcode(value){
            if(barcode.size() != 27 || barcode.front() != '1' || barcode.back() != '1')
                throw invalid_argument("POSTNET must contain 27 bars with 1 at each end.");
            decodeBarcode();
        }
        int getZipCode() const{return decodeBarcode();}
        string getBarcode() const{return barcode;}
};

int main(){
    ZipCode zip1(99504);
    cout << zip1.getZipCode() << "\n" << zip1.getBarcode() << "\n";
    ZipCode zip2("110100101000101011000010011");
    cout << zip2.getZipCode() << "\n" << zip2.getBarcode() << "\n";
    return 0;
}
