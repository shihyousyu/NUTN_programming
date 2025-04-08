#include<iostream>
#include<string>
using namespace std;

class ZipCode{
    private:
        string barcode;
        int decodeBarcode(){
            int zipCode = 0;
            for(int i = 1; i < barcode.size() - 1; i += 5)
                zipCode = zipCode * 10 + decodeGroup(barcode.substr(i, 5));
            return zipCode;
        }
        int decodeGroup(const string& group){
            int sum = 0;
            int values[] = {7, 4, 2, 1, 0};
            for(int i = 0; i < 5; i++)
                if(group[i] == '1')
                    sum += values[i];
            return(sum == 11) ? 0 : sum;
        }
        string encodeBarcode(int zipCode){
            string result = "";
            for(int i = 0; i < 5; i++){
                int digit = zipCode % 10;
                zipCode /= 10;
                result = encodeGroup(digit) + result;
            }
            result = "1" + result + "1";
            return result;
        }
        string encodeGroup(int digit){
            string group = "00000";
            int values[] = {7, 4, 2, 1, 0};
            for(int i = 0; i < 5; i++)
                if(digit >= values[i]){
                    group[i] = '1';
                    digit -= values[i];
                }
            return group;
        }
    public:
        ZipCode(int zipCode){barcode = encodeBarcode(zipCode);}
        ZipCode(const string& barcodeString){barcode = barcodeString;}
        int getZipCode(){return decodeBarcode();}
        string getBarcode() const{return barcode;}
};

int main(){
    ZipCode zip1(99504);
    cout << zip1.getZipCode() << "\n";
    cout << zip1.getBarcode() << "\n";
    ZipCode zip2("110100101000101011000010011");
    cout << zip2.getZipCode() << "\n";
    cout << zip2.getBarcode() << "\n";
    return 0;
}