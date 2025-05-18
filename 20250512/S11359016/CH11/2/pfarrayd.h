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
            bool full() const;

            int getCapacity() const;
            int getNumberUsed() const;

            void emptyArray();
            
            double& operator [](int index);
            PFArrayD& operator =(const PFArrayD& rightSide);
    };
}

#endif