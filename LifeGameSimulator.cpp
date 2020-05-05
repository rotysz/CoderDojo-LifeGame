#include "LifeGameSimulator.h"



LifeGameSimulator::LifeGameSimulator()
{
    //ctor
    m_generation_count = 0;
    for (int i = 0; i < CELL_TABLE_SIZE;i++)
        for (int  j = 0; j < CELL_TABLE_SIZE; j++)
            m_cell_table[i][j] = false;
}

void LifeGameSimulator::ClearAllCells()
{
    //ctor
    m_generation_count = 0;
    for (int i = 0; i < CELL_TABLE_SIZE;i++)
        for (int  j = 0; j < CELL_TABLE_SIZE; j++)
            m_cell_table[i][j] = false;
}

 bool LifeGameSimulator::IsCellAlive (int x_, int y_){

    return m_cell_table [x_][y_];
 }

void LifeGameSimulator::SetCellValue (int x_, int y_,bool value_){

   m_cell_table [x_][y_] = value_;
}

unsigned int LifeGameSimulator::GetGenerationNumber() {

  return m_generation_count;
}

unsigned int LifeGameSimulator::CountNeighbours (int x_, int y_) {

  int neighbours_count = 0;
  for (int i = max(0,x_-1); i <= min(x_+1, CELL_TABLE_SIZE);i++)
    for (int j = max (0, y_ -1 ); j <= min(y_+1,CELL_TABLE_SIZE);j++)
      if (!(i == x_ && j == y_))
        if (IsCellAlive(i,j))
          neighbours_count ++;

   return neighbours_count;
}

bool LifeGameSimulator::SimulateOneCell (int x_, int y_) {

  int neighbours_count = CountNeighbours(x_, y_);
  bool new_state;

  if (IsCellAlive(x_,y_)) {
    if (neighbours_count == 2 || neighbours_count == 3)
        new_state = true;
    else
        new_state = false;
  }
  else {
    if (neighbours_count == 3)
      new_state = true;
    else
      new_state = false;
  }
  return new_state;
}

void LifeGameSimulator::RunSimulation(){

    for (int i = 0; i < CELL_TABLE_SIZE;i++)
        for (int  j = 0; j < CELL_TABLE_SIZE; j++)
          new_m_cell_table[i][j] = SimulateOneCell(i,j);

     for (int i = 0; i < CELL_TABLE_SIZE;i++)
        for (int  j = 0; j < CELL_TABLE_SIZE; j++)
           m_cell_table[i][j] = new_m_cell_table[i][j];
    m_generation_count++;
}
