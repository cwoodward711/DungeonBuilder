#include "GameWindow.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main(cli::array<String^>^ args) {
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);
   DungeonBuilder::GameWindow form;
   Application::Run(% form);
}
