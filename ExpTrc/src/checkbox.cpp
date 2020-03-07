/*.cpp file for Checkbox class*/

#include "checkbox.h"


Checkbox::Checkbox(QWidget* parent)
	:QCheckBox(parent)
{

}


void Checkbox::uncheckAny(std::array<Checkbox*, 3> chbs) {
	for (Checkbox* chb : chbs) {
		chb->setChecked(false);
	}
}
