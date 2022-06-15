#pragma once
#include"ctime"
#include "Controller.h"
#include"files.h"
#include"GameOver.h"
#include"Youwin.h"

namespace Proyectofinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmMain
	/// </summary>
	public ref class FrmMain : public System::Windows::Forms::Form
	{
	public:
		FrmMain(int Nagentes, int Ntime, int Nhabitantes, int Nalidos )
		{
			int hp;
			srand(time(NULL));
			InitializeComponent();
			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Bitmaps
			bmpMap = gcnew Bitmap("mapa.png");
			bmpAgente = gcnew Bitmap("enemigo.png");
			bmplider = gcnew Bitmap("Lider1.2.png");
			bmpAliados = gcnew Bitmap("Aliados1.2.png");
			bmpHabitantes = gcnew Bitmap("habitantes.png");
			bmpComodin = gcnew Bitmap("manzana2.png");
			bmpllamas = gcnew Bitmap("llamas1.1.png");

			//file
			file = new File();
			file->reaData();

	
			//Controller
			controller = new Controller(bmplider, bmpAgente, bmpAliados,bmpHabitantes,bmpComodin,bmpllamas, Ntime ,Nagentes,Nhabitantes, hp, Nalidos);
		}

	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;


		//Bitmaps
		Bitmap^ bmpllamas;
		Bitmap^ bmpHabitantes;
		Bitmap^ bmpMap;
		Bitmap^ bmpAgente;
		Bitmap^ bmplider;
		Bitmap^ bmpAliados;
		Bitmap^ bmpComodin;

		//File
		File* file;
	private: System::Windows::Forms::Label^ lblX;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Label^ lblY;
	private: System::Windows::Forms::Label^ lblTime;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timerComodin;


		//Controller
		Controller* controller;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblTime = (gcnew System::Windows::Forms::Label());
			this->lblY = (gcnew System::Windows::Forms::Label());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->lblX = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerComodin = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->lblTime);
			this->panel1->Controls->Add(this->lblY);
			this->panel1->Controls->Add(this->lblVidas);
			this->panel1->Controls->Add(this->lblX);
			this->panel1->Location = System::Drawing::Point(2, -2);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(909, 496);
			this->panel1->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(370, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"TIEMPO";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"VIDA";
			// 
			// lblTime
			// 
			this->lblTime->AutoSize = true;
			this->lblTime->Location = System::Drawing::Point(424, 22);
			this->lblTime->Name = L"lblTime";
			this->lblTime->Size = System::Drawing::Size(35, 13);
			this->lblTime->TabIndex = 3;
			this->lblTime->Text = L"label1";
			// 
			// lblY
			// 
			this->lblY->AutoSize = true;
			this->lblY->Location = System::Drawing::Point(581, 22);
			this->lblY->Name = L"lblY";
			this->lblY->Size = System::Drawing::Size(12, 13);
			this->lblY->TabIndex = 2;
			this->lblY->Text = L"y";
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->Location = System::Drawing::Point(56, 22);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(32, 13);
			this->lblVidas->TabIndex = 1;
			this->lblVidas->Text = L"vidas";
			// 
			// lblX
			// 
			this->lblX->AutoSize = true;
			this->lblX->Location = System::Drawing::Point(517, 22);
			this->lblX->Name = L"lblX";
			this->lblX->Size = System::Drawing::Size(12, 13);
			this->lblX->TabIndex = 0;
			this->lblX->Text = L"x";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmMain::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &FrmMain::timer2_Tick);
			// 
			// timerComodin
			// 
			this->timerComodin->Enabled = true;
			this->timerComodin->Interval = 5000;
			this->timerComodin->Tick += gcnew System::EventHandler(this, &FrmMain::timerComodin_Tick);
			// 
			// FrmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(912, 496);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"FrmMain";
			this->Text = L"FrmMain";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMain::FrmMain_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Clear
		buffer->Graphics->Clear(Color::WhiteSmoke);
		//colisión
		controller->colision();
		//Move
		controller->moveEverything(buffer->Graphics);
		//Draw
		buffer->Graphics->DrawImage(bmpMap, 0, 0, panel1->Width, panel1->Height);

		lblVidas->Text = ""+ controller->getLider()->gethp();
		lblX->Text = "";
		lblX->Text = "" + controller->getLider()->getX();
		lblY->Text = "";
		lblY->Text = "" + controller->getLider()->getY();
		lblTime->Text =""+  controller->getTime();
		controller->drawEverything(buffer->Graphics, bmplider, bmpAgente, bmpAliados,bmpHabitantes,bmpComodin, bmpllamas);
		

		//Condiciones
		if (controller->getLider()->gethp() == 0) {
			//timer1->Enabled = false;
			//GameOver^ fmr = gcnew GameOver();
			//fmr->ShowDialog();
			//this->Close();
		}
		else if (controller->getTime() == 0) {
			timer1->Enabled = false;
			GameOver^ fmr = gcnew GameOver();
			fmr->ShowDialog();
			
			this->Close();
		}
		else if (controller->getLider()->gethp() == 100 || controller->getLider()->gethp() > 100) {
			timer1->Enabled = false;
			Youwin^ fmr = gcnew Youwin();
			fmr->ShowDialog();

			this->Close();

		}
		else
		{
			buffer->Render(g);
		}

	}
	private: System::Void FrmMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A: case Keys::Left:
			controller->getLider()->move(buffer->Graphics, 'A'); break;
		case Keys::D: case Keys::Right:
			controller->getLider()->move(buffer->Graphics, 'D'); break;
		case Keys::W: case Keys::Up:
			controller->getLider()->move(buffer->Graphics, 'W'); break;
		case Keys::S: case Keys::Down:
			controller->getLider()->move(buffer->Graphics, 'S'); break;
		case Keys::Space:
			Aliados* b = new Aliados(bmpAliados->Width/4, bmpAliados->Height/4,2);
			controller->addAliados(b);


		}

	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		controller->decreaseTime();
	}
    private: System::Void timerComodin_Tick(System::Object^ sender, System::EventArgs^ e) {
		Comodin* m = new Comodin(bmpComodin->Width, bmpComodin->Height);
		controller->addcomdin(m);
    }
};
}