#include "GameController.h"

GameController::GameController(Label^ inTurnNumber, Label^ inManaAmount)
{
   turnNumber = inTurnNumber;
   manaAmount = inManaAmount;

   turnNum = 1;
   turnNumber->Text = "Turn " + turnNum.ToString();
   mana = manaIncrement;
   manaAmount->Text = mana.ToString() + "/" + maxMana.ToString();
}

void GameController::spendMana(int cost)
{
   mana -= cost;
   manaAmount->Text = mana.ToString() + "/" + maxMana.ToString();
}

void GameController::manaGain(int amount)
{
   mana += amount;
   if (mana > maxMana)
      mana = maxMana;
   manaAmount->Text = mana.ToString() + "/" + maxMana.ToString();
}

void GameController::endTurn()
{
   turnNum++;
   turnNumber->Text = "Turn " + turnNum.ToString();
   mana += manaIncrement;
   if (mana > maxMana)
      mana = maxMana;
   manaAmount->Text = mana.ToString() + "/" + maxMana.ToString();
}

void GameController::setMana(int mana)
{
    this->mana = mana;
    manaAmount->Text = mana.ToString() + "/" + maxMana.ToString();
}
void GameController::setTurn(int turnNum)
{
    this->turnNum = turnNum;    
    turnNumber->Text = "Turn " + turnNum.ToString();
}