import java.util.ArrayList;

public class MessagePost extends Post{
    protected String messageContent;
    protected ArrayList<Post> listMP; //Posts feitos Message Post

    //MessagePost Constructor
    public MessagePost(int p_id,boolean p_visiblity,String p_comments,String p_author,String p_messageContent){
        super(p_id,p_visiblity,p_comments,p_author);
        this.messageContent = p_messageContent;
        this.listMP = new ArrayList<>();
    }

    //Methods
    @Override
    public int getLikes(){
        return likes;
    }
    @Override
    public int getId(){
        return id;
    }
    @Override
    public long getTimeSincePosted(){
        return timestamp;
    }
    @Override
    public boolean getVisibility(){
        return visibility;
    }
    @Override
    public String getComments(){
        return comments;
    }
    @Override
    public String getAuthor(){
        return author;
    }
    
    public String getMessageContent(){
        return messageContent;
    }

    public void setMessageContent(String p_messageContent){
        this.messageContent = p_messageContent;
    }

    public void createMessagePost(Post newMP){ //creates a new object Message Post
        listMP.add(newMP);
    }
}