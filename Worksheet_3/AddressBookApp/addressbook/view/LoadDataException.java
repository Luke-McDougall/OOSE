/**
 * Author: Luke McDougall
 * Purpose: Custom exception class used to inform calling code that 
 * important data was not loaded.
 */
package addressbook.view;

public class LoadDataException extends Exception
{
    public LoadDataException(String message, Throwable cause)
    {
        super(message, cause);
    }
}
