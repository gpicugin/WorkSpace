using System;

namespace Lib
{
    public class Window
    {
        IMethodForm _mf;
        public Window(IMethodForm Form)
        {
            _mf = Form;
        }
        public void Method_window()
        {
            Console.WriteLine("method from Window");
            _mf.Method_Form();
        }
    }

    public interface IMethodForm
    {
        void Method_Form();
    }

    interface IPrinter
    {
        void Print(string text);
    } 

    class Book
    {
        public string Text { get; set; }
        public IPrinter Printer { get; set; }

        public Book(IPrinter printer)
        {
            this.Printer = printer;
        }

        public void Print()
        {
            Printer.Print(Text);
        }
    }

    class ConsolePrinter : IPrinter
    {
        public void Print(string text)
        {
            Console.WriteLine("Печать на консоли");
        }
    }

    class HtmlPrinter : IPrinter
    {
        public void Print(string text)
        {
            Console.WriteLine("Печать в html");
        }
    }


}
