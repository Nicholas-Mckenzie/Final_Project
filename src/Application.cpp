
#include <wx/log.h>


#include <Application.h>




Application::Application()
{
}


bool Application::OnInit()
{
	window = new MainWindow("Hello world");
	window->Center();
	window->Show();

	return true;
}