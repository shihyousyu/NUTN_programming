#ifndef PFARRAYD_H
#define PFARRAYD_H

namespace PFAD{
    class PFArrayD{
        private:
            double* a;
            int capacity;
            int used;
        public:
            PFArrayD();
            PFArrayD(int capacityValue);
            PFArrayD(const PFArrayD& pfaObject);
            ~PFArrayD();

            void addElement(double element);
            bool full() const{return (capacity == used);}

            int getCapacity() const{return capacity;}
            int getNumberUsed() const{return used;}

            void emptyArray(){used = 0;}
            
            double& operator [](int index);
            PFArrayD& operator =(const PFArrayD& rightSide);
    };
}

#endif