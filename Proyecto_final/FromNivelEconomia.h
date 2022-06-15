#pragma once
#include"Controller.h"
#include"files.h"
#include"ctime"
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
	/// Resumen de FromNivelEconomia
	/// </summary>
	public ref class FromNivelEconomia : public System::Windows::Forms::Form
	{
	public:
		FromNivelEconomia(int Nagentes, int Ntime, int Nhabitantes, int Ncontador)
		{
			int hp;
			srand(time(NULL));
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			bmpMap = gcnew Bitmap("mapa2.jpeg");
			bmpAgente = gcnew Bitmap("Agentes2.png");
			bmplider = gcnew Bitmap("lider2.png");
			bmpAliados = gcnew Bitmap("aliados2.png");
			bmpHabitantes = gcnew Bitmap("_habitantes2.png");
			bmpComodin = gcnew Bitmap("monedas 2.1.png");
			bmpInflacion = gcnew Bitmap("Inflacion .png");

			//file
			file = new File();
			file->reaData();


			//Controller
			controller = new Controller(bmplider, bmpAgente, bmpAliados, bmpHabitantes,bmpComodin,bmpInflacion,  Ntime, Nagentes,Nhabitantes ,hp, Ncontador);

		}
	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;


		//Bitmaps
		Bitmap^ bmpInflacion;
		Bitmap^ bmpHabitantes;
		Bitmap^ bmpMap;
		Bitmap^ bmpAgente;
		Bitmap^ bmplider;
		Bitmap^ bmpAliados;
		Bitmap^ bmpComodin;

		//File
		File* file;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ lblY;
	private: System::Windows::Forms::Label^ lblX;
	private: System::Windows::Forms::Label^ lblTime;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Timer^ timercomdin;

		//Controller
		Controller* controller;

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FromNivelEconomia()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->lblY = (gcnew System::Windows::Forms::Label());
			this->lblX = (gcnew System::Windows::Forms::Label());
			this->lblTime = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timercomdin = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->lblY);
			this->panel1->Controls->Add(this->lblX);
			this->panel1->Controls->Add(this->lblTime);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->lblVidas);
			this->panel1->Location = System::Drawing::Point(0, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(839, 495);
			this->panel1->TabIndex = 0;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(319, 35);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(48, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"TIEMPO";
			// 
			// lblY
			// 
			this->lblY->AutoSize = true;
			this->lblY->Location = System::Drawing::Point(531, 35);
			this->lblY->Name = L"lblY";
			this->lblY->Size = System::Drawing::Size(35, 13);
			this->lblY->TabIndex = 4;
			this->lblY->Text = L"label5";
			// 
			// lblX
			// 
			this->lblX->AutoSize = true;
			this->lblX->Location = System::Drawing::Point(463, 35);
			this->lblX->Name = L"lblX";
			this->lblX->Size = System::Drawing::Size(35, 13);
			this->lblX->TabIndex = 3;
			this->lblX->Text = L"label4";
			// 
			// lblTime
			// 
			this->lblTime->AutoSize = true;
			this->lblTime->Location = System::Drawing::Point(386, 35);
			this->lblTime->Name = L"lblTime";
			this->lblTime->Size = System::Drawing::Size(35, 13);
			this->lblTime->TabIndex = 2;
			this->lblTime->Text = L"label3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"DINERO";
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->Location = System::Drawing::Point(68, 26);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(35, 13);
			this->lblVidas->TabIndex = 0;
			this->lblVidas->Text = L"label1";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FromNivelEconomia::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &FromNivelEconomia::timer2_Tick);
			// 
			// timercomdin
			// 
			this->timercomdin->Enabled = true;
			this->timercomdin->Interval = 10000;
			this->timercomdin->Tick += gcnew System::EventHandler(this, &FromNivelEconomia::timercomdin_Tick);
			// 
			// FromNivelEconomia
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(837, 495);
			this->Controls->Add(this->panel1);
			this->Name = L"FromNivelEconomia";
			this->Text = L"FromNivelEconomia";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FromNivelEconomia::FromNivelEconomia_KeyDown);
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
		lblVidas->Text = "" + controller->getLider()->gethp();
		lblX->Text = "";
		lblX->Text = "" + controller->getLider()->getX();
		lblY->Text = "";
		lblY->Text = "" + controller->getLider()->getY();
		lblTime->Text = "" + controller->getTime();

		controller->drawEverything(buffer->Graphics, bmplider, bmpAgente, bmpAliados, bmpHabitantes, bmpComodin, bmpInflacion);

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
    private: System::Void FromNivelEconomia_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
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
    		Aliados* b = new Aliados(bmpAliados->Width / 4, bmpAliados->Height / 4, 2);
    
    		controller->addAliados(b);
    	}
    }
    private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	    controller->decreaseTime();
    }
private: System::Void timercomdin_Tick(System::Object^ sender, System::EventArgs^ e) {
	Comodin* m = new Comodin(bmpComodin->Width , bmpComodin->Height );
	controller->addcomdin(m);
}
};
}
