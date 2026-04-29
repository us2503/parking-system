class Billing
{
public:
    virtual int calculateBill(int hours)
    {
        return 20 * hours;
    }

    virtual ~Billing() {}
};

class CarBilling : public Billing
{
public:
    int calculateBill(int hours)
    {
        return 20 * hours;
    }
};

class BikeBilling : public Billing
{
public:
    int calculateBill(int hours)
    {
        return 10 * hours;
    }
};

class TruckBilling : public Billing
{
public:
    int calculateBill(int hours)
    {
        return 30 * hours;
    }
};