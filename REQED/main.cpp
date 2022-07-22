#include "GUI.h"
using namespace REQED;
using namespace System::Windows::Forms;
using namespace System;
[STAThreadAttribute]

void main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    REQED::GUI form;
    Application::Run(% form);
}