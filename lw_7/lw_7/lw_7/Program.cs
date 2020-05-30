using System;
using System.IO;
using System.Net;
using System.Net.Http;
using System.Text;

namespace lw_7
{
    class Program
    {
        public static void RequestOnPage(string uri)
        {
            var webRequest = WebRequest.Create(uri);

            using (var response = webRequest.GetResponse())
            using (var content = response.GetResponseStream())
            using (var reader = new StreamReader(content))
            {
                var strContent = reader.ReadToEnd();
                Console.WriteLine(strContent);
            }

            Console.ReadLine();
        }

        static void Main(string[] args)
        {
            RequestOnPage("http://localhost:1234/message_1");
            RequestOnPage("http://localhost:1234/message_2");
            RequestOnPage("http://localhost:1234/message_3");
        }
    }
}
