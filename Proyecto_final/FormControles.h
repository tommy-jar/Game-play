#pragma once

#include"MyFrmPrincipal.h"

namespace Proyectofinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormConfiguration
	/// </summary>
	public ref class FormConfiguration : public System::Windows::Forms::Form
	{
	public:
		FormControles(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			bmpfondo = gcnew Bitmap("Controles.png");
		}
	private:
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;



		Bitmap^ bmpfondo;

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button1;


		



	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormConfiguration()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::ComponentModel::IContainer^ components;
	protected:

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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(-1, -1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(784, 407);
			this->panel1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormConfiguration::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(678, 364);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(89, 34);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Volver";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FormConfiguration::button1_Click);
			// 
			// FormConfiguration
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(783, 405);
			this->Controls->Add(this->panel1);
			this->Name = L"FormConfiguration";
			this->Text = L"FormConfiguration";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		//MyFrmPrincipal^ fmr = gcnew MyFrmPrincipal();

		
		//this->Visible = false;
		//fmr->ShowDialog();
		//this->Visible = true;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		buffer->Graphics->Clear(Color::WhiteSmoke);

		buffer->Graphics->DrawImage(bmpfondo, 0, 0, panel1->Width, panel1->Height);

		buffer->Render(g);
	}
	

};
}
