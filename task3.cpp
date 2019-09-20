/* Все ли хорошо в этом коде? */

Файл legacy.c


int values[3];


/* Файл modern.cpp */


#define LEGACY_SIZE 3
extern int *values; // необходимо объявить также как и в файлу legacy.c - extern int values[3]

class MyBlah {...};

class Adapter
{
public:
    Adapter()
    {
for (int i = 0; i < LEGACY_SIZE; ++i)
    		map_[values[i]] = new MyBlah (values[i]);
    }

// объекты создаются динамически, следовательно, необходим деструктор
    
private:
    std::map<int, MyBlah *> map_;
};
