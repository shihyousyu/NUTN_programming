import java.security.SecureRandom;
import java.util.*;

public class DeckOfCards{
    private static final SecureRandom randomNumbers = new SecureRandom();
    private static final int NUMBER_OF_CARDS = 52;
    private Card[] deck = new Card[NUMBER_OF_CARDS];
    private int currentCard = 0;

    public DeckOfCards(){
        String[] faces = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
                "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
        String[] suits = {"Hearts", "Diamonds", "Clubs", "Spades"};

        for(int count = 0; count < deck.length; count++)
            deck[count] = new Card(faces[count % 13], suits[count / 13]);
    }

    public void shuffle(){
        currentCard = 0;
        for(int first = 0; first < deck.length; first++){
            int second = randomNumbers.nextInt(NUMBER_OF_CARDS);
            Card temp = deck[first];
            deck[first] = deck[second];
            deck[second] = temp;
        }
    }

    public Card dealCard(){
        if(currentCard < deck.length)
            return deck[currentCard++];
        else
            return null;
    }

    public Card[] dealHand(int n){
        Card[] hand = new Card[n];
        for(int i = 0; i < n; i++)
            hand[i] = dealCard();
        return hand;
    }

    private static int faceValue(String face){
        switch(face){
            case "Ace": return 14;
            case "King": return 13;
            case "Queen": return 12;
            case "Jack": return 11;
            case "Ten": return 10;
            case "Nine": return 9;
            case "Eight": return 8;
            case "Seven": return 7;
            case "Six": return 6;
            case "Five": return 5;
            case "Four": return 4;
            case "Three": return 3;
            case "Deuce": return 2;
            default: return 0;
        }
    }

    private static Map<String, Integer> countFaces(Card[] hand){
        Map<String, Integer> map = new HashMap<>();
        for(Card c : hand)
            map.put(c.getFace(), map.getOrDefault(c.getFace(), 0) + 1);
        return map;
    }

    public static boolean isPair(Card[] hand){
        Map<String, Integer> faces = countFaces(hand);
        int pairs = 0;
        for(int count : faces.values())
            if(count == 2) pairs++;
        return pairs == 1;
    }

    public static boolean isTwoPair(Card[] hand){
        Map<String, Integer> faces = countFaces(hand);
        int pairs = 0;
        for(int count : faces.values())
            if(count == 2) pairs++;
        return pairs == 2;
    }

    public static boolean isThreeOfAKind(Card[] hand){
        Map<String, Integer> faces = countFaces(hand);
        return faces.containsValue(3);
    }

    public static boolean isFourOfAKind(Card[] hand){
        Map<String, Integer> faces = countFaces(hand);
        return faces.containsValue(4);
    }

    public static boolean isFlush(Card[] hand){
        String suit = hand[0].getSuit();
        for(Card c : hand)
            if(!c.getSuit().equals(suit))
                return false;
        return true;
    }

    public static boolean isStraight(Card[] hand){
        int[] values = new int[5];
        for(int i = 0; i < 5; i++)
            values[i] = faceValue(hand[i].getFace());
        Arrays.sort(values);

        for(int i = 0; i < 4; i++)
            if(values[i + 1] - values[i] != 1)
                return false;
        return true;
    }

    public static boolean isFullHouse(Card[] hand){
        Map<String, Integer> faces = countFaces(hand);
        return faces.containsValue(3) && faces.containsValue(2);
    }
}