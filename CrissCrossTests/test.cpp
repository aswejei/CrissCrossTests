#include "pch.h"
#include "C:\Users\nikit\source\repos\mycrisscross\mycrisscross\GameFieldInteractive.h"
#include "C:\Users\nikit\source\repos\mycrisscross\mycrisscross\InputChecker.h"
#include "C:\Users\nikit\source\repos\mycrisscross\mycrisscross\GameFieldUI.h"
#include "C:\Users\nikit\source\repos\mycrisscross\mycrisscross\UIInterface.h"
#include "C:\Users\nikit\source\repos\mycrisscross\mycrisscross\WinsChecker.h"
TEST(InputCheck, IdInput) {
	EXPECT_EQ(InputChecker::CrissCrossChecker("X"), true);
	EXPECT_EQ(InputChecker::CrissCrossChecker("0"), true);
	EXPECT_EQ(InputChecker::CrissCrossChecker("e"), false);
	EXPECT_EQ(InputChecker::CrissCrossChecker("f f"), false);
	EXPECT_EQ(InputChecker::CrissCrossChecker("AD;F,DALFX"), false);
	EXPECT_EQ(InputChecker::CrissCrossChecker("XXX"), false);
	EXPECT_EQ(InputChecker::CrissCrossChecker("000"), false);
}
TEST(InputCheck, StartInput) {
	EXPECT_EQ(InputChecker::Startchecker("start"), true);
	EXPECT_EQ(InputChecker::Startchecker("startt"), false);
	EXPECT_EQ(InputChecker::Startchecker("sstart"), false);
	EXPECT_EQ(InputChecker::Startchecker("start start"), false);
	EXPECT_EQ(InputChecker::Startchecker("START"), false);
	EXPECT_EQ(InputChecker::Startchecker("somgowmgt"), false);
	EXPECT_EQ(InputChecker::Startchecker("sta rt"), false);
}
TEST(InputCheck, MoveInput) {
	EXPECT_EQ(InputChecker::MoveChecker("0"), true);
	EXPECT_EQ(InputChecker::MoveChecker("1"), true);
	EXPECT_EQ(InputChecker::MoveChecker("2"), true);
	EXPECT_EQ(InputChecker::MoveChecker("3"), true);
	EXPECT_EQ(InputChecker::MoveChecker("4"), true);
	EXPECT_EQ(InputChecker::MoveChecker("5"), true);
	EXPECT_EQ(InputChecker::MoveChecker("6"), true);
	EXPECT_EQ(InputChecker::MoveChecker("7"), true);
	EXPECT_EQ(InputChecker::MoveChecker("8"), true);
	EXPECT_EQ(InputChecker::MoveChecker("00"), false);
	EXPECT_EQ(InputChecker::MoveChecker("11"), false);
	EXPECT_EQ(InputChecker::MoveChecker("22"), false);
	EXPECT_EQ(InputChecker::MoveChecker("33"), false);
	EXPECT_EQ(InputChecker::MoveChecker("44"), false);
	EXPECT_EQ(InputChecker::MoveChecker("55"), false);
	EXPECT_EQ(InputChecker::MoveChecker("66"), false);
	EXPECT_EQ(InputChecker::MoveChecker("77"), false);
	EXPECT_EQ(InputChecker::MoveChecker("88"), false);
	EXPECT_EQ(InputChecker::MoveChecker("0 0"), false);
	EXPECT_EQ(InputChecker::MoveChecker("1 1"), false);
	EXPECT_EQ(InputChecker::MoveChecker("2 2"), false);
	EXPECT_EQ(InputChecker::MoveChecker("3 3"), false);
	EXPECT_EQ(InputChecker::MoveChecker("4 4"), false);
	EXPECT_EQ(InputChecker::MoveChecker("5 5"), false);
	EXPECT_EQ(InputChecker::MoveChecker("6 6"), false);
	EXPECT_EQ(InputChecker::MoveChecker("7 7"), false);
	EXPECT_EQ(InputChecker::MoveChecker("8 8"), false);
	EXPECT_EQ(InputChecker::MoveChecker("0-"), false);
	EXPECT_EQ(InputChecker::MoveChecker("1-"), false);
	EXPECT_EQ(InputChecker::MoveChecker("2-"), false);
	EXPECT_EQ(InputChecker::MoveChecker("3-"), false);
	EXPECT_EQ(InputChecker::MoveChecker("4-"), false);
	EXPECT_EQ(InputChecker::MoveChecker("5-"), false);
	EXPECT_EQ(InputChecker::MoveChecker("6-"), false);
	EXPECT_EQ(InputChecker::MoveChecker("7-"), false);
	EXPECT_EQ(InputChecker::MoveChecker("8-"), false);
	EXPECT_EQ(InputChecker::MoveChecker("-0"), false);
	EXPECT_EQ(InputChecker::MoveChecker("-1"), false);
	EXPECT_EQ(InputChecker::MoveChecker("-2"), false);
	EXPECT_EQ(InputChecker::MoveChecker("-3"), false);
	EXPECT_EQ(InputChecker::MoveChecker("-4"), false);
	EXPECT_EQ(InputChecker::MoveChecker("-5"), false);
	EXPECT_EQ(InputChecker::MoveChecker("-6"), false);
	EXPECT_EQ(InputChecker::MoveChecker("-7"), false);
	EXPECT_EQ(InputChecker::MoveChecker("-8"), false);
	EXPECT_EQ(InputChecker::MoveChecker("e"), false);
	EXPECT_EQ(InputChecker::MoveChecker("f f"), false);
	EXPECT_EQ(InputChecker::MoveChecker("AD;F,DALFX"), false);
	EXPECT_EQ(InputChecker::MoveChecker("XXX"), false);
	EXPECT_EQ(InputChecker::MoveChecker("000"), false);
}
TEST(WinsCheckerTest, XWinCheck) 
{
	WinsChecker *wc1=new WinsChecker();
	wc1->CheckFieldState(0, true);
	wc1->CheckFieldState(1, true);
	char k = wc1->CheckFieldState(2, true);
	EXPECT_EQ(k, '0');
	delete wc1;
}
TEST(WinsCheckerTest, 0WinCheck) 
{
	WinsChecker* wc1 = new WinsChecker();
	wc1->CheckFieldState(0, false);
	wc1->CheckFieldState(1, false);
	char k = wc1->CheckFieldState(2, false);
	EXPECT_EQ(k, 'X');
	delete wc1;
}
TEST(WinsCheckerTest, Drawcheck) 
{
	WinsChecker* wc1 = new WinsChecker();
	wc1->CheckFieldState(0, false);
	wc1->CheckFieldState(4, true);
	wc1->CheckFieldState(1, false);
	wc1->CheckFieldState(2, true);
	wc1->CheckFieldState(5, false);
	wc1->CheckFieldState(3, true);
	wc1->CheckFieldState(6, false);
	wc1->CheckFieldState(7, true);
	char k =wc1->CheckFieldState(8, false);
	EXPECT_EQ(k, 'D');
	delete wc1;
}
TEST(GameFieldUITest, 0sMoveDisplayCheck) {
	GameFieldUI* gfu1 = new GameFieldUI();
	gfu1->setGameField3(true, 0);
	EXPECT_EQ(gfu1->GetGameField(0), '0');
	delete gfu1;
}
TEST(GameFieldUITest, XsMoveDisplayCheck) {
	GameFieldUI* gfu1 = new GameFieldUI();
	gfu1->setGameField3(false, 0);
	EXPECT_EQ(gfu1->GetGameField(0), 'X');
	delete gfu1;
}
TEST(GameFieldInteractiveTest, CheckMovePossibilityCheck) 
{
	GameFieldInteractive* gfi1 = new GameFieldInteractive();
	gfi1->GetMove(0, true);
	bool x = gfi1->CheckMovePossibility(0);
	EXPECT_EQ(x, false);
	bool y = gfi1->CheckMovePossibility(1);
	EXPECT_EQ(y, true);
	delete gfi1;
}
TEST(GameFieldInteractiveTest, MoveCorrectanceCheck) 
{
	GameFieldInteractive* gfi1 = new GameFieldInteractive();
	gfi1->GetMove(0, true);
	EXPECT_EQ(gfi1->GetGameField(0), true);
	gfi1->GetMove(1, true);
	EXPECT_EQ(gfi1->GetGameField(1), true);
	gfi1->GetMove(2, true);
	EXPECT_EQ(gfi1->GetGameField(2), true);
	gfi1->GetMove(3, true);
	EXPECT_EQ(gfi1->GetGameField(3), true);
	gfi1->GetMove(4, true);
	EXPECT_EQ(gfi1->GetGameField(4), true);
	gfi1->GetMove(5, true);
	EXPECT_EQ(gfi1->GetGameField(5), true);
	gfi1->GetMove(6, true);
	EXPECT_EQ(gfi1->GetGameField(6), true);
	gfi1->GetMove(7, true);
	EXPECT_EQ(gfi1->GetGameField(7), true);
	gfi1->GetMove(8, true);
	EXPECT_EQ(gfi1->GetGameField(8), true);

	delete gfi1;
}

/*
x 0 x
0 0 x
x x 0

*/