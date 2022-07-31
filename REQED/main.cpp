#include "GUI.h"
#include "Controller.h"
using namespace REQED;
using namespace System::Windows::Forms;
using namespace System;
[STAThreadAttribute]

void main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew GUI);
}