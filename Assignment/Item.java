public class Item
{
    private String name;
    private int value;
    private int effectMin;
    private int effectMax;

    public Item(String name, int value, int effectMin, int effectMax)
    {
        this.name = name;
        this.value = value;
        this.effectMin = effectMin;
        this.effectMax = effectMax;
    }

    public int getValue()
    {
        return value;
    }

    public String getName()
    {
        return name;
    }
}
