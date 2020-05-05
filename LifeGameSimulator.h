#ifndef LIFEGAMESIMULATOR_H
#define LIFEGAMESIMULATOR_H

#define CELL_TABLE_SIZE 256
#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

class LifeGameSimulator
{
    public:

        LifeGameSimulator();
        bool IsCellAlive (int x_, int y_);
        void SetCellValue (int x_, int y_, bool value_);
        unsigned int GetGenerationNumber();
        unsigned int CountNeighbours (int x_, int y_);
        bool SimulateOneCell (int x_, int y_);
        void RunSimulation();
        void ClearAllCells();


    protected:

    private:
        unsigned int m_generation_count;
        bool m_cell_table [CELL_TABLE_SIZE][CELL_TABLE_SIZE];
        bool new_m_cell_table [CELL_TABLE_SIZE][CELL_TABLE_SIZE];

};

#endif // LIFEGAMESIMULATOR_H
