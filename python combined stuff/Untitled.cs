using System;
using System.Data.SqlClient;
using System.IO;
using System.Web;
using DocumentFormat.OpenXml;
using DocumentFormat.OpenXml.Packaging;
using DocumentFormat.OpenXml.Wordprocessing;

namespace development.media 
{
    public class word_doc 
    {
        public void createDoc(string filename)
        {
            string templatePath = HttpContext.Current.Server.MapPath("~/cont/template.docx");
            string outputPath = HttpContext.Current.Server.MapPath("~/cont/" + filename);
            
            try 
            {
                if (File.Exists(outputPath))
                {
                    File.Delete(outputPath);
                }
                
                File.Copy(templatePath, outputPath);

                using (WordprocessingDocument wordDocument = WordprocessingDocument.Open(outputPath, true))
                {
                    MainDocumentPart mainPart = wordDocument.MainDocumentPart;
                    if (mainPart == null)
                    {
                        mainPart = wordDocument.AddMainDocumentPart();
                        new Document(new Body()).Save(mainPart);
                    }

                    Body docBody = mainPart.Document.Body;
                    docBody.RemoveAllChildren();

                    // Fetch data from the database
                    string connectionString = "YourConnectionString";
                    string query = "SELECT * FROM YourTable";

                    using (SqlConnection connection = new SqlConnection(connectionString))
                    {
                        connection.Open();
                        SqlCommand command = new SqlCommand(query, connection);
                        SqlDataReader reader = command.ExecuteReader();

                        // Loop through the result set and add data to the Word document
                        while (reader.Read())
                        {
                            // Example: Insert each row's data into the Word document
                            string rowData = $"{reader["Column1"].ToString()} - {reader["Column2"].ToString()}";

                            // Create paragraph, run, and text elements
                            Paragraph paragraph = new Paragraph();
                            Run run = new Run();
                            Text text = new Text(rowData);

                            // Append text to run, run to paragraph, and paragraph to body
                            run.Append(text);
                            paragraph.Append(run);
                            docBody.Append(paragraph);
                        }

                        // Close the data reader
                        reader.Close();
                    }
                }
            }
            catch (Exception e) 
            {
                // Handle exception appropriately, e.g., logging or displaying an error message
                Console.WriteLine("An error occurred: " + e.Message);
            }
        }
    }
}

using System;
using System.Data.SqlClient;
using System.IO;
using System.Xml;
using DocumentFormat.OpenXml;
using DocumentFormat.OpenXml.Packaging;
using DocumentFormat.OpenXml.Wordprocessing;

public class WordDocumentGenerator
{
    public void GenerateDocumentFromDatabase(string filename)
    {
        // Database connection string
        string connectionString = "YourConnectionString";
        
        try
        {
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                // Open the connection
                connection.Open();
                
                // Fetch data from the database
                string coverQuery = "SELECT * FROM cover";
                string paragraphQuery = "SELECT * FROM paragraph";
                string textQuery = "SELECT * FROM text";
                
                // Execute the queries
                XmlDocument xmlDoc = new XmlDocument();
                XmlElement root = xmlDoc.CreateElement("document");
                xmlDoc.AppendChild(root);
                
                // Fetch and append data for 'cover' table
                XmlElement coverElement = FetchDataAndAppendToXml(connection, coverQuery, xmlDoc, "cover");
                root.AppendChild(coverElement);
                
                // Fetch and append data for 'paragraph' table
                XmlElement paragraphElement = FetchDataAndAppendToXml(connection, paragraphQuery, xmlDoc, "paragraph");
                root.AppendChild(paragraphElement);
                
                // Fetch and append data for 'text' table
                XmlElement textElement = FetchDataAndAppendToXml(connection, textQuery, xmlDoc, "text");
                root.AppendChild(textElement);
                
                // Generate Word document from XML
                GenerateWordDocument(xmlDoc, filename);
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine("Error: " + ex.Message);
        }
    }
    
    private XmlElement FetchDataAndAppendToXml(SqlConnection connection, string query, XmlDocument xmlDoc, string elementName)
    {
        // Create an XML element for the table data
        XmlElement tableElement = xmlDoc.CreateElement(elementName);
        
        // Execute the query
        SqlCommand command = new SqlCommand(query, connection);
        SqlDataReader reader = command.ExecuteReader();
        
        // Read the data and populate the XML element
        while (reader.Read())
        {
            XmlElement rowElement = xmlDoc.CreateElement("row");
            for (int i = 0; i < reader.FieldCount; i++)
            {
                string fieldName = reader.GetName(i);
                string fieldValue = reader[i].ToString();
                
                // Create an XML attribute for each field in the row
                XmlAttribute attribute = xmlDoc.CreateAttribute(fieldName);
                attribute.Value = fieldValue;
                rowElement.Attributes.Append(attribute);
            }
            tableElement.AppendChild(rowElement);
        }
        reader.Close();
        
        return tableElement;
    }
    
    private void GenerateWordDocument(XmlDocument xmlDoc, string filename)
    {
        using (WordprocessingDocument wordDocument = WordprocessingDocument.Create(filename, WordprocessingDocumentType.Document))
        {
            MainDocumentPart mainPart = wordDocument.AddMainDocumentPart();
            mainPart.Document = new Document();
            Body body = mainPart.Document.AppendChild(new Body());
            
            // Iterate through XML elements and apply formatting
            foreach (XmlNode node in xmlDoc.DocumentElement.ChildNodes)
            {
                Paragraph paragraph = body.AppendChild(new Paragraph());
                
                // Apply formatting based on XML element and attributes
                ApplyFormatting(paragraph, node);
            }
        }
    }
    
    private void ApplyFormatting(Paragraph paragraph, XmlNode xmlNode)
    {
        // Extract data and formatting properties from xmlNode
        // Apply formatting to the paragraph based on the extracted properties
        // For example, set justification, font size, bold, underline, etc.
        foreach (XmlAttribute attribute in xmlNode.Attributes)
        {
            switch (attribute.Name)
            {
                case "justification":
                    // Set justification
                    SetJustification(paragraph, attribute.Value);
                    break;
                case "font-size":
                    // Set font size
                    SetFontSize(paragraph, attribute.Value);
                    break;
                case "bold":
                    // Set bold
                    SetBold(paragraph, attribute.Value);
                    break;
                // Add cases for other formatting properties (underline, italic, etc.)
            }
        }
        
        // Set text content of the paragraph
        paragraph.AppendChild(new Run(new Text(xmlNode.InnerText)));
    }
    
    private void SetJustification(Paragraph paragraph, string justification)
    {
        // Set justification based on the value
        switch (justification)
        {
            case "left":
                paragraph.ParagraphProperties = new ParagraphProperties(new Justification() { Val = JustificationValues.Left });
                break;
            case "right":
                paragraph.ParagraphProperties = new ParagraphProperties(new Justification() { Val = JustificationValues.Right });
                break;
            case "center":
                paragraph.ParagraphProperties = new ParagraphProperties(new Justification() { Val = JustificationValues.Center });
                break;
            // Add cases for other justification values
        }
    }
    
    private void SetFontSize(Paragraph paragraph, string fontSize)
    {
        // Set font size based on the value
        if (int.TryParse(fontSize, out int size))
        {
            paragraph.ParagraphProperties = new ParagraphProperties(new FontSize() { Val = (size * 2).ToString() });
        }
    }
    
    private void SetBold(Paragraph paragraph, string bold)
    {
        // Set bold based on the value
        if (bool.TryParse(bold, out bool isBold) && isBold)
        {
            paragraph.AppendChild(new RunProperties(new Bold()));
        }
    }
    
    // Implement methods for other formatting properties (underline, italic, etc.) if needed
}

class Program
{
    static void Main(string[] args)
    {
        WordDocumentGenerator generator = new WordDocumentGenerator();
        generator.GenerateDocumentFromDatabase("output.docx");
    }
    