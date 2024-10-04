#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <limits>

// Abstract class Bank (instead of interface in Java)
class Bank {
public:
    virtual std::string getName() const = 0;
    virtual std::string getEstablishedDate() const = 0;
    virtual std::string getBankType() const = 0;
    virtual std::string getBranchName() const = 0;
    virtual void getInfo() const = 0;
    virtual ~Bank() {}
};

// Abstract class Loan (instead of interface in Java)
class Loan {
public:
    virtual std::vector<std::string> getAvailableLoans() const = 0;
    virtual double getInterestRate(int loanType) const = 0;
    virtual std::vector<std::string> getDocumentRequired(int loanType) const = 0;
    virtual ~Loan() {}
};

// HDFC Class implementing Bank and Loan
class HDFC : public Bank, public Loan {
public:
    std::string getName() const override {
        return "HDFC";
    }

    std::string getEstablishedDate() const override {
        return "1995";
    }

    std::string getBankType() const override {
        return "Private";
    }

    std::string getBranchName() const override {
        return "Chennai";
    }

    void getInfo() const override {
        std::cout << "Bank Details: \n";
        std::cout << "Bank Name: " << getName() << "\n";
        std::cout << "Established Date: " << getEstablishedDate() << "\n";
        std::cout << "Bank Type: " << getBankType() << "\n";
        std::cout << "Branch Name: " << getBranchName() << "\n";
        std::cout << "Available Loans: [";
        for (const auto& loan : getAvailableLoans()) {
            std::cout << loan << " ";
        }
        std::cout << "]\n";
        std::cout << "Interest Rates: [" << getInterestRate(1) << ", " << getInterestRate(2) << ", " << getInterestRate(3) << "]\n";
    }

    std::vector<std::string> getAvailableLoans() const override {
        return {"Home Loan", "Gold Loan", "Personal Loan"};
    }

    double getInterestRate(int loanType) const override {
        if (loanType == 1) return 9.6;
        else if (loanType == 2) return 7.2;
        else return 13.2;
    }

    std::vector<std::string> getDocumentRequired(int loanType) const override {
        if (loanType == 1) return {"Land Papers", "ID Proof", "Income Proof"};
        else if (loanType == 2) return {"ID Proof", "Gold Valuation", "Income Proof"};
        else return {"ID Proof", "Income Proof", "Residence Proof"};
    }
};

// SBI Class implementing Bank and Loan
class SBI : public Bank, public Loan {
public:
    std::string getName() const override {
        return "SBI";
    }

    std::string getEstablishedDate() const override {
        return "1955";
    }

    std::string getBankType() const override {
        return "Public";
    }

    std::string getBranchName() const override {
        return "Madurai";
    }

    void getInfo() const override {
        std::cout << "Bank Details: \n";
        std::cout << "Bank Name: " << getName() << "\n";
        std::cout << "Established Date: " << getEstablishedDate() << "\n";
        std::cout << "Bank Type: " << getBankType() << "\n";
        std::cout << "Branch Name: " << getBranchName() << "\n";
        for (const auto& loan : getAvailableLoans()) {
            std::cout << loan << " ";
        }
        std::cout << "]\n";
        std::cout << "Interest Rates: [" << getInterestRate(1) << ", " << getInterestRate(2) << ", " << getInterestRate(3) << "]\n";
    }

    std::vector<std::string> getAvailableLoans() const override {
        return {"Home Loan", "Gold Loan", "Personal Loan"};
    }

    double getInterestRate(int loanType) const override {
        if (loanType == 1) return 9.1;
        else if (loanType == 2) return 7.5;
        else return 11.2;
    }

    std::vector<std::string> getDocumentRequired(int loanType) const override {
        if (loanType == 1) return {"Land Papers", "ID Proof", "Income Proof"};
        else if (loanType == 2) return {"ID Proof", "Gold Valuation", "Income Proof"};
        else return {"ID Proof", "Income Proof", "Residence Proof"};
    }
};

// Other bank classes (ICICI, IB) would be implemented similarly to HDFC and SBI.
class ICICI : public Bank, public Loan {
public:
    std::string getName() const override {
        return "ICICI";
    }

    std::string getEstablishedDate() const override {
        return "1994";
    }

    std::string getBankType() const override {
        return "Private";
    }

    std::string getBranchName() const override {
        return "Mumbai";
    }

    void getInfo() const override {
        std::cout << "Bank Details: \n";
        std::cout << "Bank Name: " << getName() << "\n";
        std::cout << "Established Date: " << getEstablishedDate() << "\n";
        std::cout << "Bank Type: " << getBankType() << "\n";
        std::cout << "Branch Name: " << getBranchName() << "\n";
        for (const auto& loan : getAvailableLoans()) {
            std::cout << loan << " ";
        }
        std::cout << "]\n";
        std::cout << "Interest Rates: [" << getInterestRate(1) << ", " << getInterestRate(2) << ", " << getInterestRate(3) << "]\n";
    }

    std::vector<std::string> getAvailableLoans() const override {
        return {"Home Loan", "Gold Loan", "Personal Loan"};
    }

    double getInterestRate(int loanType) const override {
        if (loanType == 1) return 8.9;
        else if (loanType == 2) return 7.7;
        else return 12.4;
    }

    std::vector<std::string> getDocumentRequired(int loanType) const override {
        if (loanType == 1) return {"Land Papers", "ID Proof", "Income Proof"};
        else if (loanType == 2) return {"ID Proof", "Gold Valuation", "Income Proof"};
        else return {"ID Proof", "Income Proof", "Residence Proof"};
    }
};
class IB : public Bank, public Loan {
public:
    std::string getName() const override {
        return "IB";
    }

    std::string getEstablishedDate() const override {
        return "1907";
    }

    std::string getBankType() const override {
        return "Public";
    }

    std::string getBranchName() const override {
        return "Coimbatore";
    }

    void getInfo() const override {
        std::cout << "Bank Details: \n";
        std::cout << "Bank Name: " << getName() << "\n";
        std::cout << "Established Date: " << getEstablishedDate() << "\n";
        std::cout << "Bank Type: " << getBankType() << "\n";
        std::cout << "Branch Name: " << getBranchName() << "\n";
        for (const auto& loan : getAvailableLoans()) {
            std::cout << loan << " ";
        }
        std::cout << "]\n";
        std::cout << "Interest Rates: [" << getInterestRate(1) << ", " << getInterestRate(2) << ", " << getInterestRate(3) << "]\n";
    }

    std::vector<std::string> getAvailableLoans() const override {
        return {"Home Loan", "Gold Loan", "Personal Loan"};
    }

    double getInterestRate(int loanType) const override {
        if (loanType == 1) return 10.1;
        else if (loanType == 2) return 7.3;
        else return 11.2;
    }

    std::vector<std::string> getDocumentRequired(int loanType) const override {
        if (loanType == 1) return {"Land Papers", "ID Proof", "Income Proof"};
        else if (loanType == 2) return {"ID Proof", "Gold Valuation", "Income Proof"};
        else return {"ID Proof", "Income Proof", "Residence Proof"};
    }
};
class Broker {
public:
    // Method to get the bank with the minimum interest rate
    static std::string getMinimumInterestBank(const std::map<std::string, double>& map) {
        double min = std::numeric_limits<double>::max();
        std::string minBank;
        for (const auto& entry : map) {
            if (entry.second < min) {
                min = entry.second;
                minBank = entry.first;
            }
        }
        return minBank;
    }

    // Compare interest rates of two banks
    static void compareInterestRates(const Bank& b1, const Bank& b2, int loanType) {
        const Loan* l1 = dynamic_cast<const Loan*>(&b1);
        const Loan* l2 = dynamic_cast<const Loan*>(&b2);


        double rate1 = l1->getInterestRate(loanType);
        double rate2 = l2->getInterestRate(loanType);

        if (rate1 < rate2) {
            std::cout << b1.getName() << " has a lower interest rate: " << rate1 << std::endl;
            b1.getInfo();
        } else {
            std::cout << b2.getName() << " has a lower interest rate: " << rate2 << std::endl;
            b2.getInfo();
        }
    }

    // Compare interest rates of three banks
    static void compareInterestRates(const Bank& b1, const Bank& b2, const Bank& b3, int loanType) {
        const Loan* l1 = dynamic_cast<const Loan*>(&b1);
        const Loan* l2 = dynamic_cast<const Loan*>(&b2);
        const Loan* l3 = dynamic_cast<const Loan*>(&b3);


        double rate1 = l1->getInterestRate(loanType);
        double rate2 = l2->getInterestRate(loanType);
        double rate3 = l3->getInterestRate(loanType);

        if (rate1 < rate2 && rate1 < rate3 ) {
            std::cout << b1.getName() << " has a lower interest rate: " << rate1 << std::endl;
            b1.getInfo();
        } else if (rate2 < rate1 && rate2 < rate3 ) {
            std::cout << b2.getName() << " has a lower interest rate: " << rate2 << std::endl;
            b1.getInfo();
        } 
        else {
            std::cout << b3.getName() << " has a lower interest rate: " << rate3 << std::endl;
            b2.getInfo();
        }
    }

    // Method to compare interest rates for multiple banks (n banks)
    static void compareInterestRates(const std::vector<Bank*>& banks, int loanType) {
        const Bank* minBank = nullptr;
        double minRate = std::numeric_limits<double>::max();

        for (const Bank* bank : banks) {
            const Loan* loan = dynamic_cast<const Loan*>(bank);
            if (!loan) continue;

            double rate = loan->getInterestRate(loanType);
            if (rate < minRate) {
                minRate = rate;
                minBank = bank;
            }
        }

        if (minBank) {
            std::cout << minBank->getName() << " has the lowest interest rate: " << minRate << std::endl;
            minBank->getInfo();
        }
    }

    //Print details for single bank
    static void printBankDetails(const Bank& b1){
        b1.getInfo();
    }
    //Print details for multiple bank
    static void printBankDetails(const std::vector<Bank*>& compareBanks,int n){
        for(int i=0;i<n;i++){
            compareBanks[i]->getInfo();
        }
    }
};

int main() {
   
    // Initialize banks
    HDFC hdfc;
    SBI sbi;
    ICICI icici;
    IB ib;
    Broker broker;

    // Map to associate bank numbers with bank objects
    std::map<int, Bank*> banks;
    banks[1] = &hdfc;
    banks[2] = &icici;
    banks[3] = &sbi;
    banks[4] = &ib;


    std::cout << "Loan Categories : \n1. Home Loan 2. Gold Loan 3. Personal Loan\n";
    std::cout << "Enter [1-3]: ";
    int loanType;
    std::cin >> loanType;

    // Map to store interest rates for each bank
    std::map<std::string, double> map;
    map["HDFC"] = hdfc.getInterestRate(loanType);
    map["ICICI"] = icici.getInterestRate(loanType);
    map["SBI"] = sbi.getInterestRate(loanType);
    map["IB"] = ib.getInterestRate(loanType);
    
    std::string minInterestBank = broker.getMinimumInterestBank(map); 
    std::cout << "Bank Details which has minimum interest : \n";
    if (minInterestBank == "HDFC") {
        hdfc.getInfo();
    } else if (minInterestBank == "ICICI") {
        icici.getInfo();
    } else if (minInterestBank == "SBI") {
        sbi.getInfo();
    } else if (minInterestBank == "IB") {
        ib.getInfo();
    }

    //Print Details of banks
    std::cout << "Print bank details [1.Print single bank 2.Print n banks]: ";
    int print;
    std::cin >> print;

    if (print == 1) {
        std::cout << "Enter bank number [1.HDFC 2.ICICI 3.SBI 4.IB]: ";
        int bankChoice;
        std::cin >> bankChoice;
        broker.printBankDetails(*banks[bankChoice]); 
    } else {
        std::cout << "All bank Details\n";
        int n;
        std::cout<<"Enter number of banks : [2-4]"<<std::endl;
        std::cin>>n;
        std::vector<Bank*> compareBanks;
        for(int i=1;i<=n;i++){
            std::cout << "Enter bank number [1.HDFC 2.ICICI 3.SBI 4.IB]: ";
            int bankChoice;
            std::cin>>bankChoice;
            compareBanks.push_back(banks[bankChoice]);
        }
       
        broker.printBankDetails(compareBanks,compareBanks.size()); // Printing all banks
    }

    //Compare between banks
    std::cout << "Compare between banks - Enter the loan type to compare \n[1. Home Loan 2. Gold Loan 3. Personal Loan]: ";
    std::cin >> loanType;

    int option;
    std::cout << "1. Compare 2 banks 2. Compare 3 banks 3. Compare N banks: ";
    std::cin >> option;

    switch (option) {
        case 1: {
            std::cout << "1.HDFC 2.ICICI 3.SBI 4.IB\n";
            std::cout << "Enter 2 banks [1-4] [No repetitions]: ";
            int b1, b2;
            std::cin >> b1 >> b2;
            broker.compareInterestRates(*banks[b1], *banks[b2], loanType); // Assuming this function is defined
            break;
        }
        case 2: {
            std::cout << "1.HDFC 2.ICICI 3.SBI 4.IB\n";
            std::cout << "Enter 3 banks [1-4] [No repetitions]: ";
            int b1, b2, b3;
            std::cin >> b1 >> b2 >> b3;
            broker.compareInterestRates(*banks[b1], *banks[b2], *banks[b3], loanType); // Assuming this function is defined
            break;
        }
        case 3: {
            std::cout << "1.HDFC 2.ICICI 3.SBI 4.IB\n";
            std::cout << "Banks available-4\n";
            std::cout << "Enter the no. of banks: ";
            int bankSize;
            std::cin >> bankSize;
            std::vector<Bank*> bank(bankSize);
            for (int i = 0; i < bankSize; ++i) {
                int bankChoice;
                std::cin >> bankChoice;
                bank[i] = banks[bankChoice]; // Assuming no invalid input
            }
            broker.compareInterestRates(bank, loanType); // Assuming this function is defined
            break;
        }
    }

    return 0;
}