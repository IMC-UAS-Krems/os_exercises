
typedef struct point {
    int x;
    int y;
} point_t;

typedef union coins {
    struct {
        int quarter;
        int dime;
        int nickel;
        int penny;
    }; 
    int coins[4];
} coins_t;